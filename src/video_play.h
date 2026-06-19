#ifndef VIDEO_PLAY_H
#define VIDEO_PLAY_H

#include "lvgl/lvgl.h"

/**
 * @brief 视频播放器模块
 *
 * 使用管道文件(FIFO) + mplayer 在指定的 LVGL Panel 区域内播放视频。
 * 支持播放/暂停、上一首/下一首、进度条拖动、快进/快退功能。
 * 所有功能封装为独立模块，不修改现有源码。
 */

/**
 * @brief 初始化视频播放器
 *
 * @param panel       用于显示视频的 LVGL Panel 控件 (如 ui_Panel2)
 * @param slider      进度条控件 (如 ui_Slider1), 用于显示/控制播放进度
 * @param btn_prev    上一首按钮 (如 ui_Image23), 可为 NULL
 * @param btn_next    下一首按钮 (如 ui_Image22), 可为 NULL
 * @param btn_play    播放/暂停按钮 (如 ui_Image21), 可为 NULL
 * @param video_list  播放列表 (字符串数组, 最后一个元素必须为 NULL)
 */
void video_play_init(lv_obj_t *panel, lv_obj_t *slider,
                     lv_obj_t *btn_prev, lv_obj_t *btn_next,
                     lv_obj_t *btn_play,
                     const char *video_list[]);

/**
 * @brief 开始/继续播放
 */
void video_play_start(void);

/**
 * @brief 暂停播放
 */
void video_play_pause(void);

/**
 * @brief 切换播放/暂停
 */
void video_play_toggle(void);

/**
 * @brief 停止播放并清理资源
 */
void video_play_stop(void);

/**
 * @brief 播放上一首
 */
void video_play_prev(void);

/**
 * @brief 播放下一首
 */
void video_play_next(void);

/**
 * @brief 快进
 * @param seconds 快进秒数
 */
void video_play_seek_forward(int seconds);

/**
 * @brief 快退
 * @param seconds 快退秒数
 */
void video_play_seek_backward(int seconds);

/**
 * @brief 跳转到指定百分比位置 (0~100)
 * @param percent 百分比
 */
void video_play_seek_to(int percent);

/**
 * @brief 发送命令给 mplayer
 * @param cmd 命令字符串
 */
void video_play_send_cmd(const char *cmd);

/**
 * @brief 检查是否正在播放
 * @return 1 正在播放, 0 未播放
 */
int video_play_is_running(void);

/**
 * @brief 卸载模块 (释放资源)
 */
void video_play_deinit(void);

#endif