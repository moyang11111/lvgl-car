/**
 * @file ui_turn_signal.h
 * @brief 左右转向灯闪烁功能接口
 *
 * 点击左/右转向按钮时，对应的转向灯图像开始闪烁；
 * 再次点击同侧按钮，停止闪烁。
 * 无需修改已有代码，只需调用本接口即可。
 */

#ifndef UI_TURN_SIGNAL_H
#define UI_TURN_SIGNAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

/**
 * @brief 初始化转向灯闪烁功能
 *        点击左侧按钮 -> 左转向灯闪烁
 *        点击右侧按钮 -> 右转向灯闪烁
 *        再次点击同一按钮 -> 停止闪烁
 *        切换侧边时，自动关闭另一侧
 *
 * @param left_btn          左转向按钮对象 (例如 ui_Button1)
 * @param right_btn         右转向按钮对象 (例如 ui_Button2)
 * @param left_img          左转向灯图像对象 (例如 ui_Image6)
 * @param right_img         右转向灯图像对象 (例如 ui_Image5)
 * @param blink_interval_ms 闪烁间隔(毫秒) (建议: 300 ~ 600ms)
 */
void ui_turn_signal_init(lv_obj_t * left_btn, lv_obj_t * right_btn,
                         lv_obj_t * left_img, lv_obj_t * right_img,
                         uint32_t blink_interval_ms);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* UI_TURN_SIGNAL_H */
