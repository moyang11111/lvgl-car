/**
 * @file ui_arc_auto_decrease.h
 * @brief 油门圆弧自动下降功能接口
 * 
 * 当油门图标被释放时，圆弧值自动下降至0。
 * 无需修改已有代码，只需调用本接口即可。
 */

#ifndef UI_ARC_AUTO_DECREASE_H
#define UI_ARC_AUTO_DECREASE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

/**
 * @brief 初始化油门自动回缩功能
 *        当油门图标被释放时，圆弧值自动下降至0；
 *        当油门图标被按下时，自动下降暂停。
 * 
 * @param arc              圆弧对象指针 (例如 ui_Arc1)
 * @param accelerator_img  油门图标对象指针 (例如 ui_Image3)
 * @param decrease_speed   每次定时器触发减少的值 (建议: -1 ~ -3)
 * @param tick_interval_ms 定时器触发间隔(毫秒) (建议: 20 ~ 50ms)
 */
void ui_arc_auto_decrease_init(lv_obj_t * arc, lv_obj_t * accelerator_img,
                                int decrease_speed, uint32_t tick_interval_ms);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* UI_ARC_AUTO_DECREASE_H */
