
#ifndef _MODELS_H
#define _MODELS_H

#ifdef __cplusplus
extern "C" {
#endif

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

LV_IMG_DECLARE(ui_img_3d_printer_bg_png);    // assets\3d_printer_bg.png
LV_IMG_DECLARE(ui_img_icn_wifi_png);    // assets\icn_wifi.png
LV_IMG_DECLARE(ui_img_icn_pc_png);    // assets\icn_pc.png
LV_IMG_DECLARE(ui_img_icn_usb_png);    // assets\icn_usb.png
LV_IMG_DECLARE(ui_img_btn_print_png);    // assets\btn_print.png
LV_IMG_DECLARE(ui_img_btn_move_png);    // assets\btn_move.png
LV_IMG_DECLARE(ui_img_btn_setting_png);    // assets\btn_setting.png
LV_IMG_DECLARE(ui_img_print_view_bg_png);    // assets\print_view_bg.png
LV_IMG_DECLARE(ui_img_print_view_front_png);    // assets\print_view_front.png
LV_IMG_DECLARE(ui_img_icn_time_1_png);    // assets\icn_time_1.png
LV_IMG_DECLARE(ui_img_icn_time_2_png);    // assets\icn_time_2.png
LV_IMG_DECLARE(ui_img_icn_head_png);    // assets\icn_head.png
LV_IMG_DECLARE(ui_img_icn_bed_png);    // assets\icn_bed.png
LV_IMG_DECLARE(ui_img_btn_print_down_png);    // assets\btn_print_down.png
LV_IMG_DECLARE(ui_img_btn_print_top_off_png);    // assets\btn_print_top_off.png
LV_IMG_DECLARE(ui_img_icn_pause_png);    // assets\icn_pause.png
LV_IMG_DECLARE(ui_img_icn_stop_png);    // assets\icn_stop.png
LV_IMG_DECLARE(ui_img_btn_z_botton_png);    // assets\btn_z_botton.png
LV_IMG_DECLARE(ui_img_btn_z_top_png);    // assets\btn_z_top.png
LV_IMG_DECLARE(ui_img_arrow_up_png);    // assets\arrow_up.png
LV_IMG_DECLARE(ui_img_arrow_down_png);    // assets\arrow_down.png
LV_IMG_DECLARE(ui_img_btn_pad_bottom_png);    // assets\btn_pad_bottom.png
LV_IMG_DECLARE(ui_img_btn_pad_top_png);    // assets\btn_pad_top.png
LV_IMG_DECLARE(ui_img_arrow_left_png);    // assets\arrow_left.png
LV_IMG_DECLARE(ui_img_arrow_right_png);    // assets\arrow_right.png
LV_IMG_DECLARE(ui_img_roller_bg_png);    // assets\roller_bg.png
LV_IMG_DECLARE(ui_img_btn_main_off_png);    // assets\btn_main_off.png
LV_IMG_DECLARE(ui_img_btn_main_on_png);    // assets\btn_main_on.png

LV_FONT_DECLARE(ui_font_Small_Font);

extern void lv_obj_set_content(lv_obj_t* obj);

extern void lv_obj_set_features(lv_obj_t* obj, lv_coord_t w, lv_coord_t h, lv_align_t align, lv_coord_t pos_x, lv_coord_t pos_y);

extern lv_obj_t* create_base_obj(lv_obj_t* parent, lv_coord_t w, lv_coord_t h);

extern lv_obj_t* create_box(lv_obj_t* parent, lv_coord_t w, lv_coord_t h);

extern lv_obj_t* create_icon(lv_obj_t* parent, const void* src);

extern lv_obj_t* create_head_label(lv_obj_t* parent, const char* label_str);

extern lv_obj_t* create_roller(lv_obj_t* parent, const char* head_name, const char* options);

extern lv_obj_t* create_btn(lv_obj_t* parent, const char* head_name);

extern lv_obj_t* create_group(lv_obj_t* parent, const char* head_name);

extern lv_obj_t* create_switch(lv_obj_t* parent, const char* head_name);

extern lv_obj_t* create_slider(lv_obj_t* parent, int32_t min, int32_t max);

extern lv_obj_t* create_statusbar(lv_obj_t* parent, const char* head_name);


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
