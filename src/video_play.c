#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#include "lvgl/lvgl.h"
#include "lvgl/src/drivers/display/fb/lv_linux_fbdev.h"
#include "src/ui/ui.h"
#include "video_play.h"

#define VIDEO_FIFO   "/fifo_video"
#define VIDEO_FIFO_SIZE 64
#define SEEK_STEP    10           /* 快进/快退步进秒数 */
#define SLIDER_TIMER_MS 500       /* 进度条定时器更新周期(ms) */

/* ============== 全局状态 ============== */

static int video_fifo_fd = -1;
static pthread_t video_thread;
static volatile int video_running = 0;
static volatile int video_paused = 0;
static lv_timer_t *slider_timer = NULL;

/* 用户传入的控件 */
static lv_obj_t *playback_panel = NULL;
static lv_obj_t *progress_slider = NULL;

/* 播放列表 */
static const char **playlist = NULL;
static int playlist_size = 0;
static int current_idx = 0;

/* ============== 内部工具函数 ============== */

/** 获取 Panel 在屏幕上的绝对坐标和尺寸 */
static void get_panel_rect(lv_obj_t *obj, int *x, int *y, int *w, int *h)
{
    lv_area_t area;
    lv_obj_get_coords(obj, &area);
    *x = area.x1;
    *y = area.y1;
    *w = lv_obj_get_width(obj);
    *h = lv_obj_get_height(obj);
    printf("视频: Panel 绝对位置 = (%d,%d), 尺寸 = %dx%d\n", *x, *y, *w, *h);
}

/** 获取播放列表中当前视频文件的路径 */
static const char *current_video_path(void)
{
    if (!playlist || current_idx < 0 || current_idx >= playlist_size)
        return NULL;
    return playlist[current_idx];
}

/** 发送命令给 mplayer (通过 FIFO) */
static void send_cmd(const char *cmd)
{
    if (video_fifo_fd >= 0) {
        write(video_fifo_fd, cmd, strlen(cmd));
        printf("视频: 发送命令 -> %s", cmd);
    }
}

/** 获取mplayer的播放进度百分比 (通过解析mplayer输出) */
static int get_media_percent(void)
{
    /* mplayer -slave 模式下, 我们可以发送 "get_percent_pos\n" 获取进度
     * 输出格式: "ANS_PERCENT_POSITION=%d"
     * 但由于 FIFO 是单向的, 实际的进度获取需要另做处理。
     * 这里通过定时器模拟: 每500ms递增1%, 满100%自动下一首
     * 更精确的做法: 使用管道读取mplayer标准输出, 解析 ANS 应答
     */
    return -1;  /* 返回-1表示由定时器模拟 */
}

/* ============== mplayer 播放线程 ============== */

static void *mplayer_thread(void *arg)
{
    (void)arg;
    int px = 0, py = 0, pw = 800, ph = 480;
    const char *video;

    /* 获取当前播放视频 */
    video = current_video_path();
    if (!video) {
        printf("视频: 播放列表为空或索引无效\n");
        return NULL;
    }

    /* 获取 Panel 位置 */
    if (playback_panel)
        get_panel_rect(playback_panel, &px, &py, &pw, &ph);

    /* 不超出屏幕 800x480 */
    if (pw > 800) pw = 800;
    if (ph > 480) ph = 480;

    /* 杀掉残留的 mplayer 进程 */
    system("killall -9 mplayer 2>/dev/null");
    usleep(200000);

    /* 创建 FIFO 管道 */
    unlink(VIDEO_FIFO);
    if (mkfifo(VIDEO_FIFO, 0777) < 0) {
        perror("mkfifo");
        return NULL;
    }

    /*
     * 为保证进度条不被视频覆盖, 将视频高度缩减 10px
     */
    int safe_h = ph - 10;
    if (safe_h < 100) safe_h = ph;

    /*
     * 启动 mplayer:
     *   -slave              : 接受标准输入命令
     *   -quiet              : 减少控制台输出
     *   -input file=        : 使用 FIFO 接收命令
     *   -vo fbdev2          : 输出到 framebuffer 设备
     *   -vf scale=W:H,format=bgra : 缩放视频, 留出进度条空间
     */
    char cmd[512];
    snprintf(cmd, sizeof(cmd),
             "mplayer -slave -quiet -input file=%s "
             "-vo fbdev2 "
             "-vf scale=%d:%d,format=bgra "
             "\"%s\" &",
             VIDEO_FIFO,
             pw, safe_h,
             video);
    printf("视频: 启动 mplayer -> %s\n", cmd);
    system(cmd);

    /* 打开 FIFO (写端) */
    video_fifo_fd = open(VIDEO_FIFO, O_WRONLY);
    if (video_fifo_fd < 0) {
        perror("open fifo");
        return NULL;
    }

    video_running = 1;
    video_paused = 0;
    printf("视频: 开始播放 [%d/%d] %s\n", current_idx + 1, playlist_size, video);

    /* 保持线程运行, 接收命令 */
    while (video_running) {
        sleep(1);
    }

    /* 清理 */
    printf("视频: 停止播放线程...\n");
    close(video_fifo_fd);
    video_fifo_fd = -1;
    system("killall -9 mplayer 2>/dev/null");
    unlink(VIDEO_FIFO);
    printf("视频: 播放线程已退出\n");

    return NULL;
}

/* ============== 进度条定时器回调 ============== */

static void slider_timer_cb(lv_timer_t *timer)
{
    (void)timer;
    if (!video_running || !progress_slider)
        return;

    /* 每500ms递增进度条, 满100%自动下一首 */
    int val = lv_slider_get_value(progress_slider);
    val += 1;
    if (val >= 100) {
        lv_slider_set_value(progress_slider, 100, LV_ANIM_OFF);
        /* 自动下一首 */
        printf("视频: 播放结束, 自动下一首\n");
        video_play_next();
    } else {
        lv_slider_set_value(progress_slider, val, LV_ANIM_OFF);
    }
}

/* ============== 按钮事件回调 ============== */

static void on_play_btn_click(lv_event_t *e)
{
    if (lv_event_get_code(e) != LV_EVENT_CLICKED)
        return;
    video_play_toggle();
}

static void on_prev_btn_click(lv_event_t *e)
{
    if (lv_event_get_code(e) != LV_EVENT_CLICKED)
        return;
    video_play_prev();
}

static void on_next_btn_click(lv_event_t *e)
{
    if (lv_event_get_code(e) != LV_EVENT_CLICKED)
        return;
    video_play_next();
}

static void on_slider_value_change(lv_event_t *e)
{
    if (lv_event_get_code(e) != LV_EVENT_VALUE_CHANGED)
        return;

    if (!video_running) return;

    lv_obj_t *slider = lv_event_get_target_obj(e);
    int val = lv_slider_get_value(slider);
    printf("视频: 拖动进度条到 %d%%\n", val);

    /* 通过百分比计算跳转位置: seek 命令接受百分比或秒数
     * seek val  # val 是百分比 (0-100)
     */
    char cmd[VIDEO_FIFO_SIZE];
    snprintf(cmd, sizeof(cmd), "seek %d 1\n", val);
    send_cmd(cmd);
}

/* ============== 外部接口 ============== */

void video_play_init(lv_obj_t *panel, lv_obj_t *slider,
                     lv_obj_t *btn_prev, lv_obj_t *btn_next,
                     lv_obj_t *btn_play,
                     const char *video_list[])
{
    /* 保存控件引用 */
    playback_panel = panel;
    progress_slider = slider;

    /* 解析播放列表 */
    playlist = video_list;
    playlist_size = 0;
    if (video_list) {
        while (video_list[playlist_size] != NULL)
            playlist_size++;
    }
    current_idx = 0;

    printf("视频: 播放列表共 %d 首\n", playlist_size);

    /* 绑定按钮事件 (如果传入的控件不为 NULL) */
    if (btn_play) {
        lv_obj_add_event_cb(btn_play, on_play_btn_click, LV_EVENT_CLICKED, NULL);
        printf("视频: 已绑定播放/暂停按钮事件\n");
    }

    if (btn_prev) {
        lv_obj_add_event_cb(btn_prev, on_prev_btn_click, LV_EVENT_CLICKED, NULL);
        printf("视频: 已绑定上一首按钮事件\n");
    }

    if (btn_next) {
        lv_obj_add_event_cb(btn_next, on_next_btn_click, LV_EVENT_CLICKED, NULL);
        printf("视频: 已绑定下一首按钮事件\n");
    }

    /* 绑定进度条拖动事件 */
    if (progress_slider) {
        lv_obj_add_event_cb(progress_slider, on_slider_value_change, LV_EVENT_VALUE_CHANGED, NULL);
        lv_slider_set_range(progress_slider, 0, 100);
        lv_slider_set_value(progress_slider, 0, LV_ANIM_OFF);
        printf("视频: 已绑定进度条事件\n");
    }

    /* 创建定时器: 每隔500ms更新进度条 */
    slider_timer = lv_timer_create(slider_timer_cb, SLIDER_TIMER_MS, NULL);

    printf("视频: 播放器初始化完成\n");
}

void video_play_start(void)
{
    if (video_running && !video_paused) {
        printf("视频: 已经在播放中\n");
        return;
    }

    if (video_running && video_paused) {
        /* 从暂停状态恢复 */
        send_cmd("pause\n");
        video_paused = 0;
        printf("视频: 继续播放\n");
        return;
    }

    /* 暂停LVGL对fb0的占用 */
    lv_linux_fbdev_suspend(lv_display_get_default());

    /* 创建并启动播放线程 */
    if (pthread_create(&video_thread, NULL, mplayer_thread, NULL) != 0) {
        perror("pthread_create");
        return;
    }
    pthread_detach(video_thread);

    /* 重置进度条 */
    if (progress_slider)
        lv_slider_set_value(progress_slider, 0, LV_ANIM_OFF);

    printf("视频: 启动播放\n");
}

void video_play_pause(void)
{
    if (!video_running) return;

    send_cmd("pause\n");
    video_paused = 1;
    printf("视频: 暂停\n");
}

void video_play_toggle(void)
{
    if (!video_running) {
        video_play_start();
        return;
    }

    if (video_paused) {
        video_play_start();  /* 继续播放 */
    } else {
        video_play_pause();
    }
}

void video_play_stop(void)
{
    if (!video_running) return;

    printf("视频: 停止播放\n");
    video_running = 0;

    send_cmd("quit\n");
    usleep(200000);
    system("killall -9 mplayer 2>/dev/null");

    if (video_fifo_fd >= 0) {
        close(video_fifo_fd);
        video_fifo_fd = -1;
    }
    unlink(VIDEO_FIFO);

    if (progress_slider)
        lv_slider_set_value(progress_slider, 0, LV_ANIM_OFF);

    /* 恢复LVGL对fb0的占用 */
    lv_linux_fbdev_resume(lv_display_get_default());

    printf("视频: 已停止\n");
}

void video_play_prev(void)
{
    if (playlist_size <= 0) return;

    current_idx = (current_idx - 1 + playlist_size) % playlist_size;
    printf("视频: 上一首 [%d/%d]\n", current_idx + 1, playlist_size);

    /* 重新启动播放 */
    video_play_stop();
    usleep(50000);
    video_play_start();
}

void video_play_next(void)
{
    if (playlist_size <= 0) return;

    current_idx = (current_idx + 1) % playlist_size;
    printf("视频: 下一首 [%d/%d]\n", current_idx + 1, playlist_size);

    /* 重新启动播放 */
    video_play_stop();
    usleep(50000);
    video_play_start();
}

void video_play_seek_forward(int seconds)
{
    char cmd[VIDEO_FIFO_SIZE];
    snprintf(cmd, sizeof(cmd), "seek %d 0\n", seconds);
    send_cmd(cmd);
    printf("视频: 快进 %d 秒\n", seconds);
}

void video_play_seek_backward(int seconds)
{
    char cmd[VIDEO_FIFO_SIZE];
    snprintf(cmd, sizeof(cmd), "seek -%d 0\n", seconds);
    send_cmd(cmd);
    printf("视频: 快退 %d 秒\n", seconds);
}

void video_play_seek_to(int percent)
{
    char cmd[VIDEO_FIFO_SIZE];
    snprintf(cmd, sizeof(cmd), "seek %d 1\n", percent);
    send_cmd(cmd);
    printf("视频: 跳转到 %d%%\n", percent);

    if (progress_slider)
        lv_slider_set_value(progress_slider, percent, LV_ANIM_OFF);
}

void video_play_send_cmd(const char *cmd)
{
    send_cmd(cmd);
}

int video_play_is_running(void)
{
    return video_running;
}

void video_play_deinit(void)
{
    video_play_stop();

    if (slider_timer) {
        lv_timer_del(slider_timer);
        slider_timer = NULL;
    }

    playback_panel = NULL;
    progress_slider = NULL;
    playlist = NULL;
    playlist_size = 0;
    current_idx = 0;

    printf("视频: 播放器模块已卸载\n");
}