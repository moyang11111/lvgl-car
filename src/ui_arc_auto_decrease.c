/**
 * @file ui_arc_auto_decrease.c
 * @brief 油门圆弧自动下降功能实现
 *
 * 原理：
 * 1. 在油门图标上注册 LV_EVENT_PRESSED 和 LV_EVENT_RELEASED 事件
 * 2. 按下油门 -> 停止定时器（允许用户手动操作增加）
 * 3. 释放油门 -> 创建/启动定时器，定时减小 arc 值
 * 4. 当 arc 值 <= 0 时，自动停止定时器
 *
 * 注意：本文件不会修改任何现有代码，通过 LVGL 的事件机制和定时器独立工作。
 */

#include "ui_arc_auto_decrease.h"
#include <stdlib.h>

/* 内部数据结构：存储单个弧的自动下降上下文 */
typedef struct {
    lv_obj_t * arc;                 /* 圆弧对象 */
    lv_obj_t * accelerator_img;     /* 油门图标对象 */
    int decrease_speed;             /* 每次减少的值（负数） */
    uint32_t tick_interval_ms;      /* 定时器触发间隔(毫秒) */
    lv_timer_t * timer;             /* 自动下降定时器 */
} arc_auto_decrease_ctx_t;

/* 定时器回调：自动减小 arc 值 */
static void arc_decrease_timer_cb(lv_timer_t * timer)
{
    arc_auto_decrease_ctx_t * ctx = (arc_auto_decrease_ctx_t *)lv_timer_get_user_data(timer);
    if (!ctx || !ctx->arc) {
        return;
    }

    int current_val = lv_arc_get_value(ctx->arc);
    int new_val = current_val + ctx->decrease_speed; /* decrease_speed 为负数 */

    if (new_val <= 0) {
        lv_arc_set_value(ctx->arc, 0);
        /* 下降到 0，停止定时器 */
        if (ctx->timer) {
            lv_timer_del(ctx->timer);
            ctx->timer = NULL;
        }
    } else {
        lv_arc_set_value(ctx->arc, new_val);
    }
}

/* 油门按下事件：停止自动下降 */
static void accelerator_pressed_cb(lv_event_t * e)
{
    arc_auto_decrease_ctx_t * ctx = (arc_auto_decrease_ctx_t *)lv_event_get_user_data(e);
    if (!ctx) return;

    if (ctx->timer) {
        lv_timer_del(ctx->timer);
        ctx->timer = NULL;
    }
}

/* 油门释放事件：启动自动下降 */
static void accelerator_released_cb(lv_event_t * e)
{
    arc_auto_decrease_ctx_t * ctx = (arc_auto_decrease_ctx_t *)lv_event_get_user_data(e);
    if (!ctx || !ctx->arc) return;

    /* 如果 arc 已经是 0，无需启动定时器 */
    if (lv_arc_get_value(ctx->arc) <= 0) {
        return;
    }

    /* 如果定时器已存在，先删除 */
    if (ctx->timer) {
        lv_timer_del(ctx->timer);
        ctx->timer = NULL;
    }

    /* 创建定时器 */
    ctx->timer = lv_timer_create(arc_decrease_timer_cb, ctx->tick_interval_ms, ctx);
    lv_timer_set_repeat_count(ctx->timer, -1); /* 无限重复 */
}

/* 用户数据释放回调 */
static void ctx_free_cb(lv_event_t * e)
{
    arc_auto_decrease_ctx_t * ctx = (arc_auto_decrease_ctx_t *)lv_event_get_user_data(e);
    if (ctx) {
        if (ctx->timer) {
            lv_timer_del(ctx->timer);
            ctx->timer = NULL;
        }
        lv_free(ctx);
    }
}

void ui_arc_auto_decrease_init(lv_obj_t * arc, lv_obj_t * accelerator_img,
                                int decrease_speed, uint32_t tick_interval_ms)
{
    if (!arc || !accelerator_img) return;

    /* 参数检查：确保 decrease_speed 为负数 */
    if (decrease_speed > 0) {
        decrease_speed = -decrease_speed;
    }

    /* 分配上下文 */
    arc_auto_decrease_ctx_t * ctx = (arc_auto_decrease_ctx_t *)lv_malloc(sizeof(arc_auto_decrease_ctx_t));
    if (!ctx) return;

    ctx->arc = arc;
    ctx->accelerator_img = accelerator_img;
    ctx->decrease_speed = decrease_speed;
    ctx->tick_interval_ms = tick_interval_ms;
    ctx->timer = NULL;

    /* 注册事件回调：
     * LV_EVENT_PRESSED  - 按下油门，停止自动下降
     * LV_EVENT_RELEASED - 释放油门，启动自动下降
     *
     * 注意：LVGL 支持同一对象多个回调，不会影响已有的 ui_event_Image3 回调
     */
    lv_obj_add_event_cb(accelerator_img, accelerator_pressed_cb, LV_EVENT_PRESSED, ctx);
    lv_obj_add_event_cb(accelerator_img, accelerator_released_cb, LV_EVENT_RELEASED, ctx);

    /* 可选：对象删除时清理内存 */
    lv_obj_add_event_cb(arc, ctx_free_cb, LV_EVENT_DELETE, ctx);
}
