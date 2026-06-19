SET(SOURCES screens/ui_Screen1.c
    screens/ui_Screen2.c
    screens/ui_Screen3.c
    screens/ui_Screen4.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_bj_png.c
    images/ui_img_zhuangshi_png.c
    images/ui_img_sudupan_png.c
    images/ui_img_youm_png.c
    images/ui_img_fill_1_png.c
    images/ui_img_shace_png.c
    images/ui_img_right6_png.c
    images/ui_img_faguangtiao_png.c
    images/ui_img_ring_left_small_png.c
    images/ui_img_ring_right_small_png.c
    images/ui_img_seatbelt_big_png.c
    images/ui_img_xxd_png.c
    images/ui_img_icon_play_png.c
    images/ui_img_icon_skip_next_png.c
    images/ui_img_icon_skip_prev_png.c
    images/ui_img_icon_playlist_png.c
    images/ui_img_icon_back_png.c
    fonts/ui_font_Font1.c
    fonts/ui_font_Font2.c
    fonts/ui_font_Font3.c
    fonts/ui_font_Font4.c
    fonts/ui_font_Font45.c
    fonts/ui_font_Font5.c
    fonts/ui_font_Font7.c)

add_library(ui ${SOURCES})
