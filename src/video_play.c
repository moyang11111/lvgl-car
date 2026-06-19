#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#include "lvgl/lvgl.h"
/* lv_linux_fbdev_suspend/resume stubs for lvgl v9.x compat */
extern void lv_linux_fbdev_suspend(void *disp);
extern void lv_linux_fbdev_resume(void *disp);
#include "src/ui/ui.h"
#include "video_play.h"

#define VIDEO_FIFO   "/fifo_video"
#define VIDEO_FIFO_SIZE 64
#define SEEK_STEP    10           /* 蹇繘/蹇€€姝ヨ繘绉掓暟 */
#define SLIDER_TIMER_MS 500       /* 杩涘害鏉″畾鏃跺櫒鏇存柊鍛ㄦ湡(ms) */

/* ============== 鍏ㄥ眬鐘舵€?============== */

static int video_fifo_fd = -1;
static pthread_t video_thread;
static volatile int video_running = 0;
static volatile int video_paused = 0;
static lv_timer_t *slider_timer = NULL;

/* 鐢ㄦ埛浼犲叆鐨勬帶浠?*/
static lv_obj_t *playback_panel = NULL;
static lv_obj_t *progress_slider = NULL;

/* 鎾斁鍒楄〃 */
static const char **playlist = NULL;
static int playlist_size = 0;
static int current_idx = 0;

/* ============== 鍐呴儴宸ュ叿鍑芥暟 ============== */

/** 鑾峰彇 Panel 鍦ㄥ睆骞曚笂鐨勭粷瀵瑰潗鏍囧拰灏哄 */
static void get_panel_rect(lv_obj_t *obj, int *x, int *y, int *w, int *h)
{
    lv_area_t area;
    lv_obj_get_coords(obj, &area);
    *x = area.x1;
    *y = area.y1;
    *w = lv_obj_get_width(obj);
    *h = lv_obj_get_height(obj);
    printf("瑙嗛: Panel 缁濆浣嶇疆 = (%d,%d), 灏哄 = %dx%d\n", *x, *y, *w, *h);
}

/** 鑾峰彇鎾斁鍒楄〃涓綋鍓嶈棰戞枃浠剁殑璺緞 */
static const char *current_video_path(void)
{
    if (!playlist || current_idx < 0 || current_idx >= playlist_size)
        return NULL;
    return playlist[current_idx];
}

/** 鍙戦€佸懡浠ょ粰 mplayer (閫氳繃 FIFO) */
static void send_cmd(const char *cmd)
{
    if (video_fifo_fd >= 0) {
        write(video_fifo_fd, cmd, strlen(cmd));
        printf("瑙嗛: 鍙戦€佸懡浠?-> %s", cmd);
    }
}

/** 鑾峰彇mplayer鐨勬挱鏀捐繘搴︾櫨鍒嗘瘮 (閫氳繃瑙ｆ瀽mplayer杈撳嚭) */
static int get_media_percent(void)
{
    /* mplayer -slave 妯″紡涓? 鎴戜滑鍙互鍙戦€?"get_percent_pos\n" 鑾峰彇杩涘害
     * 杈撳嚭鏍煎紡: "ANS_PERCENT_POSITION=%d"
     * 浣嗙敱浜?FIFO 鏄崟鍚戠殑, 瀹為檯鐨勮繘搴﹁幏鍙栭渶瑕佸彟鍋氬鐞嗐€?
     * 杩欓噷閫氳繃瀹氭椂鍣ㄦā鎷? 姣?00ms閫掑1%, 婊?00%鑷姩涓嬩竴棣?
     * 鏇寸簿纭殑鍋氭硶: 浣跨敤绠￠亾璇诲彇mplayer鏍囧噯杈撳嚭, 瑙ｆ瀽 ANS 搴旂瓟
     */
    return -1;  /* 杩斿洖-1琛ㄧず鐢卞畾鏃跺櫒妯℃嫙 */
}

/* ============== mplayer 鎾斁绾跨▼ ============== */

static void *mplayer_thread(void *arg)
{
    (void)arg;
    int px = 0, py = 0, pw = 800, ph = 480;
    const char *video;

    /* 鑾峰彇褰撳墠鎾斁瑙嗛 */
    video = current_video_path();
    if (!video) {
        printf("瑙嗛: 鎾斁鍒楄〃涓虹┖鎴栫储寮曟棤鏁圽n");
        return NULL;
    }

    /* 鑾峰彇 Panel 浣嶇疆 */
    if (playback_panel)
        get_panel_rect(playback_panel, &px, &py, &pw, &ph);

    /* 涓嶈秴鍑哄睆骞?800x480 */
    if (pw > 800) pw = 800;
    if (ph > 480) ph = 480;

    /* 鏉€鎺夋畫鐣欑殑 mplayer 杩涚▼ */
    system("killall -9 mplayer 2>/dev/null");
    usleep(200000);

    /* 鍒涘缓 FIFO 绠￠亾 */
    unlink(VIDEO_FIFO);
    if (mkfifo(VIDEO_FIFO, 0777) < 0) {
        perror("mkfifo");
        return NULL;
    }

    /*
     * 涓轰繚璇佽繘搴︽潯涓嶈瑙嗛瑕嗙洊, 灏嗚棰戦珮搴︾缉鍑?10px
     */
    int safe_h = ph - 10;
    if (safe_h < 100) safe_h = ph;

    /*
     * 鍚姩 mplayer:
     *   -slave              : 鎺ュ彈鏍囧噯杈撳叆鍛戒护
     *   -quiet              : 鍑忓皯鎺у埗鍙拌緭鍑?
     *   -input file=        : 浣跨敤 FIFO 鎺ユ敹鍛戒护
     *   -vo fbdev2          : 杈撳嚭鍒?framebuffer 璁惧
     *   -vf scale=W:H,format=bgra : 缂╂斁瑙嗛, 鐣欏嚭杩涘害鏉＄┖闂?
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
    printf("瑙嗛: 鍚姩 mplayer -> %s\n", cmd);
    system(cmd);

    /* 鎵撳紑 FIFO (鍐欑) */
    video_fifo_fd = open(VIDEO_FIFO, O_WRONLY);
    if (video_fifo_fd < 0) {
        perror("open fifo");
        return NULL;
    }

    video_running = 1;
    video_paused = 0;
    printf("瑙嗛: 寮€濮嬫挱鏀?[%d/%d] %s\n", current_idx + 1, playlist_size, video);

    /* 淇濇寔绾跨▼杩愯, 鎺ユ敹鍛戒护 */
    while (video_running) {
        sleep(1);
    }

    /* 娓呯悊 */
    printf("瑙嗛: 鍋滄鎾斁绾跨▼...\n");
    close(video_fifo_fd);
    video_fifo_fd = -1;
    system("killall -9 mplayer 2>/dev/null");
    unlink(VIDEO_FIFO);
    printf("瑙嗛: 鎾斁绾跨▼宸查€€鍑篭n");

    return NULL;
}

/* ============== 杩涘害鏉″畾鏃跺櫒鍥炶皟 ============== */

static void slider_timer_cb(lv_timer_t *timer)
{
    (void)timer;
    if (!video_running || !progress_slider)
        return;

    /* 姣?00ms閫掑杩涘害鏉? 婊?00%鑷姩涓嬩竴棣?*/
    int val = lv_slider_get_value(progress_slider);
    val += 1;
    if (val >= 100) {
        lv_slider_set_value(progress_slider, 100, LV_ANIM_OFF);
        /* 鑷姩涓嬩竴棣?*/
        printf("瑙嗛: 鎾斁缁撴潫, 鑷姩涓嬩竴棣朶n");
        video_play_next();
    } else {
        lv_slider_set_value(progress_slider, val, LV_ANIM_OFF);
    }
}

/* ============== 鎸夐挳浜嬩欢鍥炶皟 ============== */

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
    printf("瑙嗛: 鎷栧姩杩涘害鏉″埌 %d%%\n", val);

    /* 閫氳繃鐧惧垎姣旇绠楄烦杞綅缃? seek 鍛戒护鎺ュ彈鐧惧垎姣旀垨绉掓暟
     * seek val  # val 鏄櫨鍒嗘瘮 (0-100)
     */
    char cmd[VIDEO_FIFO_SIZE];
    snprintf(cmd, sizeof(cmd), "seek %d 1\n", val);
    send_cmd(cmd);
}

/* ============== 澶栭儴鎺ュ彛 ============== */

void video_play_init(lv_obj_t *panel, lv_obj_t *slider,
                     lv_obj_t *btn_prev, lv_obj_t *btn_next,
                     lv_obj_t *btn_play,
                     const char *video_list[])
{
    /* 淇濆瓨鎺т欢寮曠敤 */
    playback_panel = panel;
    progress_slider = slider;

    /* 瑙ｆ瀽鎾斁鍒楄〃 */
    playlist = video_list;
    playlist_size = 0;
    if (video_list) {
        while (video_list[playlist_size] != NULL)
            playlist_size++;
    }
    current_idx = 0;

    printf("瑙嗛: 鎾斁鍒楄〃鍏?%d 棣朶n", playlist_size);

    /* 缁戝畾鎸夐挳浜嬩欢 (濡傛灉浼犲叆鐨勬帶浠朵笉涓?NULL) */
    if (btn_play) {
        lv_obj_add_event_cb(btn_play, on_play_btn_click, LV_EVENT_CLICKED, NULL);
        printf("瑙嗛: 宸茬粦瀹氭挱鏀?鏆傚仠鎸夐挳浜嬩欢\n");
    }

    if (btn_prev) {
        lv_obj_add_event_cb(btn_prev, on_prev_btn_click, LV_EVENT_CLICKED, NULL);
        printf("瑙嗛: 宸茬粦瀹氫笂涓€棣栨寜閽簨浠禱n");
    }

    if (btn_next) {
        lv_obj_add_event_cb(btn_next, on_next_btn_click, LV_EVENT_CLICKED, NULL);
        printf("瑙嗛: 宸茬粦瀹氫笅涓€棣栨寜閽簨浠禱n");
    }

    /* 缁戝畾杩涘害鏉℃嫋鍔ㄤ簨浠?*/
    if (progress_slider) {
        lv_obj_add_event_cb(progress_slider, on_slider_value_change, LV_EVENT_VALUE_CHANGED, NULL);
        lv_slider_set_range(progress_slider, 0, 100);
        lv_slider_set_value(progress_slider, 0, LV_ANIM_OFF);
        printf("瑙嗛: 宸茬粦瀹氳繘搴︽潯浜嬩欢\n");
    }

    /* 鍒涘缓瀹氭椂鍣? 姣忛殧500ms鏇存柊杩涘害鏉?*/
    slider_timer = lv_timer_create(slider_timer_cb, SLIDER_TIMER_MS, NULL);

    printf("瑙嗛: 鎾斁鍣ㄥ垵濮嬪寲瀹屾垚\n");
}

void video_play_start(void)
{
    if (video_running && !video_paused) {
        printf("瑙嗛: 宸茬粡鍦ㄦ挱鏀句腑\n");
        return;
    }

    if (video_running && video_paused) {
        /* 浠庢殏鍋滅姸鎬佹仮澶?*/
        send_cmd("pause\n");
        video_paused = 0;
        printf("瑙嗛: 缁х画鎾斁\n");
        return;
    }

    /* 鏆傚仠LVGL瀵筬b0鐨勫崰鐢?*/
    lv_linux_fbdev_suspend(lv_display_get_default());

    /* 鍒涘缓骞跺惎鍔ㄦ挱鏀剧嚎绋?*/
    if (pthread_create(&video_thread, NULL, mplayer_thread, NULL) != 0) {
        perror("pthread_create");
        return;
    }
    pthread_detach(video_thread);

    /* 閲嶇疆杩涘害鏉?*/
    if (progress_slider)
        lv_slider_set_value(progress_slider, 0, LV_ANIM_OFF);

    printf("瑙嗛: 鍚姩鎾斁\n");
}

void video_play_pause(void)
{
    if (!video_running) return;

    send_cmd("pause\n");
    video_paused = 1;
    printf("瑙嗛: 鏆傚仠\n");
}

void video_play_toggle(void)
{
    if (!video_running) {
        video_play_start();
        return;
    }

    if (video_paused) {
        video_play_start();  /* 缁х画鎾斁 */
    } else {
        video_play_pause();
    }
}

void video_play_stop(void)
{
    if (!video_running) return;

    printf("瑙嗛: 鍋滄鎾斁\n");
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

    /* 鎭㈠LVGL瀵筬b0鐨勫崰鐢?*/
    lv_linux_fbdev_resume(lv_display_get_default());

    printf("瑙嗛: 宸插仠姝n");
}

void video_play_prev(void)
{
    if (playlist_size <= 0) return;

    current_idx = (current_idx - 1 + playlist_size) % playlist_size;
    printf("瑙嗛: 涓婁竴棣?[%d/%d]\n", current_idx + 1, playlist_size);

    /* 閲嶆柊鍚姩鎾斁 */
    video_play_stop();
    usleep(50000);
    video_play_start();
}

void video_play_next(void)
{
    if (playlist_size <= 0) return;

    current_idx = (current_idx + 1) % playlist_size;
    printf("瑙嗛: 涓嬩竴棣?[%d/%d]\n", current_idx + 1, playlist_size);

    /* 閲嶆柊鍚姩鎾斁 */
    video_play_stop();
    usleep(50000);
    video_play_start();
}

void video_play_seek_forward(int seconds)
{
    char cmd[VIDEO_FIFO_SIZE];
    snprintf(cmd, sizeof(cmd), "seek %d 0\n", seconds);
    send_cmd(cmd);
    printf("瑙嗛: 蹇繘 %d 绉抃n", seconds);
}

void video_play_seek_backward(int seconds)
{
    char cmd[VIDEO_FIFO_SIZE];
    snprintf(cmd, sizeof(cmd), "seek -%d 0\n", seconds);
    send_cmd(cmd);
    printf("瑙嗛: 蹇€€ %d 绉抃n", seconds);
}

void video_play_seek_to(int percent)
{
    char cmd[VIDEO_FIFO_SIZE];
    snprintf(cmd, sizeof(cmd), "seek %d 1\n", percent);
    send_cmd(cmd);
    printf("瑙嗛: 璺宠浆鍒?%d%%\n", percent);

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

    printf("瑙嗛: 鎾斁鍣ㄦā鍧楀凡鍗歌浇\n");
}