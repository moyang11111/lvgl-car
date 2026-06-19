#include <stdio.h>
#include "lvgl/lvgl.h"
#include "UI/ui.h"
#include "UI/screens/ui_Screen4.h"
#include "video_play.h"


//static void my_timer1(lv_timer_t * timer)
//{
   // int *user_data = lv_timer_get_user_data(timer);

   // uint32_t idle = lv_timer_get_idle(); //返回 LVGL 在空闲状态花费的时间（单位：毫秒）
  //  LV_LOG_USER("my_timer1 user_data: %d, idle: %d", *user_data, idle);
 //   LV_LOG_USER("6666\n");
//}


//事件回调
//static void event_handler(lv_event_t * e)
//{
    //lv_event_code_t code = lv_event_get_code(e);  //获取事件类型

    //if(code == LV_EVENT_CLICKED) {
        //LV_LOG_USER("Clicked");
    //}
    //else if(code == LV_EVENT_VALUE_CHANGED) {
        //LV_LOG_USER("Toggled");
    //}
//}

             ////键盘事件回调函数/////
//static void ta_event_cb(lv_event_t * e)
//{
    //lv_event_code_t code = lv_event_get_code(e);
    //lv_obj_t * ta = lv_event_get_target(e);
    //lv_obj_t * kb = lv_event_get_user_data(e);
    //if(code == LV_EVENT_FOCUSED) {
        //lv_keyboard_set_textarea(kb, ta);
        //lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);
    //}

    //if(code == LV_EVENT_DEFOCUSED) {
        //lv_keyboard_set_textarea(kb, NULL);
        //lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    //}
//}

void mymain(void)
{
       ///////第一个lvgl的代码，创建一个对象//////
    //lv_obj_t * per1 = lv_obj_create(lv_scr_act());   //在当前屏幕上创建一个对象
    //6818的屏幕 x:800 y:480
    //lv_obj_set_pos(per1,100,50);     //移动位置
    //lv_obj_set_size(per1,400,100);     //改变大小
    
    //lv_obj_t * per2 = lv_obj_create(per1);   //per1为父对象
    //lv_obj_set_size(per2,100,60);                      //设置大小
    //lv_obj_align(per2,LV_ALIGN_CENTER,0,0);         //对齐
    //lv_obj_align_to(per2,per,LV_ALIGN_OUT_BOTTOM_RIGHT,0,0);    //以per为基准对齐
    //lv_obj_set_pos(per2,100,100);


         ///////第二个例子：创建控键/////
    //lv_obj_t * btn2 = lv_obj_create(lv_scr_act());   //创建按钮
    //lv_obj_align(btn2,LV_ALIGN_CENTER,0,40);          //居中对齐
    //lv_obj_set_size(btn2,50,30);


        ////////带标签的按钮////////
    //lv_obj_t * btn = lv_obj_create(lv_scr_act());
    //lv_obj_align(btn,LV_ALIGN_CENTER,0,0);
    //lv_obj_set_size(btn,100,50);

    //lv_obj_t * label = lv_label_create(btn);
    //lv_label_set_text(label,"hello");
    //lv_obj_align(label,LV_ALIGN_CENTER,0,0);
    //lv_obj_set_size(label,50,50);


    //定时器//
    //static int user_data = 100;

     //lv_timer_t * timer1;
     /* 创建第一个timer */
   // timer1 = lv_timer_create(my_timer1, 100, &user_data);
    // timer1 = lv_timer_create(my_timer1, 100, NULL);
     //lv_timer_set_repeat_count(timer1, 3);



     //lv_example_keyboard_1();
    


            ///////第六个图像////////

     //LV_IMAGE_DECLARE(xxd);
     //lv_obj_t * img1 =lv_image_create(lv_screen_active());
     //lv_image_set_src(img1,&xxd);
     //lv_obj_align(img1,LV_ALIGN_CENTER,0,0);


         ////////创建一个gif///////
      //2.创建一个gif图片对象 
    //LV_IMAGE_DECLARE(gif1);    //声明图片的素材
    //lv_obj_t * gif = lv_gif_create(lv_screen_active());     //创建一个GIF控件
    //lv_gif_set_src(gif, "A:gif1.gif");                             //使用图片素材
    //lv_obj_align(gif, LV_ALIGN_CENTER, 0, 0);               //设置图片的位置


          ////////事件////////
    //lv_obj_t * label;

    //lv_obj_t * btn1 = lv_button_create(lv_screen_active());

    //LVGL事件
    //lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);

    //lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);
    //lv_obj_remove_flag(btn1, LV_OBJ_FLAG_PRESS_LOCK);

    //label = lv_label_create(btn1);
    //lv_label_set_text(label, "Button");
    //lv_obj_center(label);

    //lv_obj_t * btn2 = lv_button_create(lv_screen_active());
    //lv_obj_add_event_cb(btn2, event_handler, LV_EVENT_ALL, NULL);
    //lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    //lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    //lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    //label = lv_label_create(btn2);
    //lv_label_set_text(label, "Toggle");
    //lv_obj_center(label);

       //////登录界面/////
   
       //LV_IMAGE_DECLARE(xxd);
       //lv_obj_t * img1 =lv_image_create(lv_screen_active());
       //lv_image_set_src(img1,&xxd);
       //lv_obj_align(img1,LV_ALIGN_CENTER,0,30);
    
    //lv_obj_t * kb = lv_keyboard_create(lv_screen_active());
    
    //lv_obj_t * label_user = lv_label_create(lv_screen_active());
    //lv_label_set_text(label_user, "Username");
    //lv_obj_align(label_user, LV_ALIGN_CENTER, -100, -100);

    //lv_obj_t * ta1;   
    //ta1 = lv_textarea_create(lv_screen_active());   //建第一个文本框
    //lv_obj_align(ta1, LV_ALIGN_CENTER, 40, -100);
    //lv_obj_add_event_cb(ta1, ta_event_cb, LV_EVENT_ALL, kb);
    //lv_textarea_set_placeholder_text(ta1, "Enter username");
    //lv_obj_set_size(ta1, 200, 40);

    //lv_obj_t * label_pwd = lv_label_create(lv_screen_active());
    //lv_label_set_text(label_pwd, "Password");
    //lv_obj_align(label_pwd, LV_ALIGN_CENTER, -100, -30);

    //lv_obj_t * ta2;
    //ta2 = lv_textarea_create(lv_screen_active());   //建第二个文本框
    //lv_obj_align(ta2, LV_ALIGN_CENTER, 40, -30);
    //lv_obj_add_event_cb(ta2, ta_event_cb, LV_EVENT_ALL, kb);
    //lv_textarea_set_placeholder_text(ta2, "Enter password");
    //lv_obj_set_size(ta2, 200, 40);

    //lv_obj_t * btn = lv_button_create(lv_screen_active());   //建立按钮
    //lv_obj_set_size(btn, 100, 30);
    //lv_obj_align_to(btn, ta2, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);   // ta2 正下方，间距20px

    //lv_obj_t * label = lv_label_create(btn);
    //lv_label_set_text(label, "Enter");
    //lv_obj_center(label);

    //lv_keyboard_set_textarea(kb, ta1);

//#if LV_USE_ARABIC_PERSIAN_CHARS && LV_FONT_DEJAVU_16_PERSIAN_HEBREW   //波斯或希伯字体需要才开
    //lv_obj_set_style_text_font(kb, &lv_font_dejavu_16_persian_hebrew, 0);
    //lv_obj_set_style_text_font(ta1, &lv_font_dejavu_16_persian_hebrew, 0);
    //lv_obj_set_style_text_font(ta2, &lv_font_dejavu_16_persian_hebrew, 0);
//#endif

// 播放列表 (最后一个元素必须为 NULL)
    static const char *video_list[] = {
        "JustinBieber-Baby.mp4",
        NULL
    };
    ui_init();

    video_play_init(ui_Panel3, ui_Slider2, ui_Image6, ui_Image5, ui_Image4, video_list);

}