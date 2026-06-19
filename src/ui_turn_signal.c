/**
 * @file ui_turn_signal.c
 * @brief 左右转向灯闪烁功能实现
 *
 * 原理：
 * 1. 在左/右按钮上注册 LV_EVENT_CLICKED 事件
 * 2. 点击按钮 -> 切换对应侧转向灯的闪烁状态
 * 3. 使用定时器周期性切换图像的隐藏/显示状态来实现闪烁
 * 4. 切换侧边时，自动取消另一侧的闪烁
 *
 * 注意：本文件不会修改任何现有代码，通过 LVGL 的事件机制和定时器独立工作。
 */

#include "ui_turn_signal.h"

/* 转向灯状态枚举 */
typedef enum {
    TURN_SIGNAL_OFF = 0,
    TURN_SIGNAL_LEFT,
    TURN_SIGNAL_RIGHT
} turn_signal_state_t;

/* 内部数据结构：储存转向灯控制上下文 */
typedef struct {
    lv_obj_t * left_btn;            // 左转向按钮
    lv_obj_t * right_btn;           // 右转向按钮
    lv_obj_t * left_img;            // 左转向灯图像
    lv_obj_t * right_img;           // 右转向灯图像
    uint32_t blink_interval_ms;     // 闪烁间隔(毫秒)
    lv_timer_t * timer;             // 闪烁定时器
    turn_signal_state_t state;      // 当前闪烁状态
} turn_signal_ctx_t;

/* 全局上下文（简化实现，仅支持一组转向灯） */
static turn_signal_ctx_t * g_ctx = NULL;

/* 前向声明 */
static void blink_timer_cb(lv_timer_t * timer);

/* 停止闪烁 */
static void stop_blink(turn_signal_ctx_t * ctx)
{
    if (!ctx) return;

    if (ctx->timer) {
        lv_timer_del(ctx->timer);
        ctx->timer = NULL;
    }

    if (ctx->left_img) {
        lv_obj_remove_flag(ctx->left_img, LV_OBJ_FLAG_HIDDEN);
    }
    if (ctx->right_img) {
        lv_obj_remove_flag(ctx->right_img, LV_OBJ_FLAG_HIDDEN);
    }

    ctx->state = TURN_SIGNAL_OFF;
}

/* 启动指定侧的闪烁 */
static void start_blink(turn_signal_ctx_t * ctx, turn_signal_state_t side)
{
    if (!ctx) return;

    if (ctx->timer) {
        lv_timer_del(ctx->timer);
        ctx->timer = NULL;
    }

    ctx->state = side;

    /* 确保对侧图像保持可见 */
    lv_obj_t * other_img  = (side == TURN_SIGNAL_LEFT) ? ctx->right_img : ctx->left_img;
    if (other_img) {
        lv_obj_remove_flag(other_img, LV_OBJ_FLAG_HIDDEN);
    }

    /* 本侧开始闪烁，初始显示 */
    lv_obj_t * target_img = (side == TURN_SIGNAL_LEFT) ? ctx->left_img : ctx->right_img;
    if (target_img) {
        lv_obj_remove_flag(target_img, LV_OBJ_FLAG_HIDDEN);
    }

    ctx->timer = lv_timer_create(blink_timer_cb, ctx->blink_interval_ms, ctx);
    if (ctx->timer) {
        lv_timer_set_repeat_count(ctx->timer, -1);
    }
}

/* 定时器回调：切换目标图像的隐藏/显示 */
static void blink_timer_cb(lv_timer_t * timer)
{
    turn_signal_ctx_t * ctx = (turn_signal_ctx_t *)lv_timer_get_user_data(timer);
    if (!ctx) return;

    lv_obj_t * target_img = NULL;
    if (ctx->state == TURN_SIGNAL_LEFT) {
        target_img = ctx->left_img;
    } else if (ctx->state == TURN_SIGNAL_RIGHT) {
        target_img = ctx->right_img;
    }

    if (!target_img) return;

    if (lv_obj_has_flag(target_img, LV_OBJ_FLAG_HIDDEN)) {
        lv_obj_remove_flag(target_img, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(target_img, LV_OBJ_FLAG_HIDDEN);
    }
}

/* 左转向按钮点击事件 */
static void left_btn_click_cb(lv_event_t * e)
{
    turn_signal_ctx_t * ctx = (turn_signal_ctx_t *)lv_event_get_user_data(e);
    if (!ctx) return;

    if (ctx->state == TURN_SIGNAL_LEFT) {
        stop_blink(ctx);
    } else {
        start_blink(ctx, TURN_SIGNAL_LEFT);
    }
}

/* 右转向按钮点击事件 */
static void right_btn_click_cb(lv_event_t * e)
{
    turn_signal_ctx_t * ctx = (turn_signal_ctx_t *)lv_event_get_user_data(e);
    if (!ctx) return;

    if (ctx->state == TURN_SIGNAL_RIGHT) {
        stop_blink(ctx);
    } else {
        start_blink(ctx, TURN_SIGNAL_RIGHT);
    }
}

void ui_turn_signal_init(lv_obj_t * left_btn, lv_obj_t * right_btn,
                         lv_obj_t * left_img, lv_obj_t * right_img,
                         uint32_t blink_interval_ms)
{
    if (!left_btn || !right_btn || !left_img || !right_img) return;
    if (blink_interval_ms < 100) blink_interval_ms = 100;

    if (g_ctx) {
        if (g_ctx->timer) {
            lv_timer_del(g_ctx->timer);
        }
        lv_free(g_ctx);
        g_ctx = NULL;
    }

    g_ctx = (turn_signal_ctx_t *)lv_malloc(sizeof(turn_signal_ctx_t));
    if (!g_ctx) return;

    g_ctx->left_btn = left_btn;
    g_ctx->right_btn = right_btn;
    g_ctx->left_img = left_img;
    g_ctx->right_img = right_img;
    g_ctx->blink_interval_ms = blink_interval_ms;
    g_ctx->timer = NULL;
    g_ctx->state = TURN_SIGNAL_OFF;

    lv_obj_remove_flag(left_img, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(right_img, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_event_cb(left_btn, left_btn_click_cb, LV_EVENT_CLICKED, g_ctx);
    lv_obj_add_event_cb(right_btn, right_btn_click_cb, LV_EVENT_CLICKED, g_ctx);
}
