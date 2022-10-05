#include "models.h"

void lv_obj_set_features(lv_obj_t* obj, lv_coord_t w, lv_coord_t h, lv_align_t align, lv_coord_t pos_x, lv_coord_t pos_y)
{
    lv_obj_set_size(obj, w, h);
    lv_obj_align(obj, align, pos_x, pos_y);
}

void lv_obj_set_content(lv_obj_t* obj)
{
    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
}

lv_obj_t* create_icon(lv_obj_t* parent, const void* src)
{
    lv_obj_t* new_icon = lv_img_create(parent);
    lv_img_set_src(new_icon, src);
    lv_obj_add_flag(new_icon, LV_OBJ_FLAG_ADV_HITTEST);
    return new_icon;
}

lv_obj_t* create_box(lv_obj_t* parent, lv_coord_t w, lv_coord_t h)
{
    lv_obj_t* box = lv_obj_create(parent);
    lv_obj_set_size(box, w, h);

    lv_obj_clear_flag(box, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(box, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(box, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(box, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(box, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(box, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(box, lv_color_hex(0x414B62), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(box, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(box, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(box, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(box, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(box, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(box, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(box, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    return box;
}


lv_obj_t* create_head_label(lv_obj_t* parent, const char* label_str)
{
    lv_obj_t* label = lv_label_create(parent);
    lv_obj_add_flag(parent, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
    lv_obj_set_features(label, LV_SIZE_CONTENT, LV_SIZE_CONTENT,
        LV_ALIGN_CENTER, 0, 0);

    lv_label_set_text(label, label_str);
    lv_label_set_recolor(label, "true");

    lv_obj_set_style_text_color(label, lv_color_hex(0xD2DCF2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);
    return label;
}

lv_obj_t* create_roller(lv_obj_t* parent, const char* head_name, const char* options)
{
    lv_obj_t* new_roller = lv_roller_create(parent);
    lv_roller_set_options(new_roller, options, LV_ROLLER_MODE_INFINITE);
    lv_obj_set_features(new_roller, 142, 131, LV_ALIGN_CENTER, 0, 0);

    lv_obj_set_style_text_color(new_roller, lv_color_hex(0x3F475E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(new_roller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(new_roller, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(new_roller, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(new_roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(new_roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(new_roller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(new_roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(new_roller, lv_color_hex(0xDBE6FF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(new_roller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(new_roller, &lv_font_montserrat_26, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(new_roller, lv_color_hex(0x3A445C), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(new_roller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    if (head_name != NULL)
    {
        lv_obj_t* label = create_head_label(parent, head_name);
        lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);
    }
    return new_roller;
}

lv_obj_t* create_btn(lv_obj_t* parent, const char* head_name)
{
    lv_obj_t* new_btn = lv_imgbtn_create(parent);
    lv_imgbtn_set_src(new_btn, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_btn_main_off_png, NULL);
    lv_imgbtn_set_src(new_btn, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_btn_main_on_png, NULL);
    lv_imgbtn_set_src(new_btn, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &ui_img_btn_main_on_png, NULL);
    lv_imgbtn_set_src(new_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &ui_img_btn_main_on_png, NULL);

    lv_obj_set_features(new_btn, LV_SIZE_CONTENT, 66,
        LV_ALIGN_LEFT_MID, 0, 0);

    lv_obj_add_flag(new_btn, LV_OBJ_FLAG_CHECKABLE);

    lv_obj_set_style_text_color(new_btn, lv_color_hex(0xABC1ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(new_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(new_btn, lv_color_hex(0x00B9FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(new_btn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_color(new_btn, lv_color_hex(0x06CEFB), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(new_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_t* btn_label = lv_label_create(new_btn);
    lv_obj_set_features(btn_label, LV_SIZE_CONTENT, LV_SIZE_CONTENT,
        LV_ALIGN_CENTER, 0, 0);

    lv_label_set_text(btn_label, head_name);
    lv_label_set_recolor(btn_label, "true");
    lv_obj_set_style_text_align(btn_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(btn_label, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);
    return new_btn;
}

lv_obj_t* create_group(lv_obj_t* parent, const char* head_name)
{
    lv_obj_t* new_group = lv_obj_create(parent);
    lv_obj_set_features(new_group, 160, 422,
        LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_style_bg_color(new_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(new_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(new_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(new_group, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(new_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    if (head_name != NULL)
    {
        lv_obj_t* label = create_head_label(new_group, head_name);
        lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);
    }
    return new_group;
}

lv_obj_t* create_switch(lv_obj_t* parent, const char* head_name)
{
    lv_obj_t* new_switch = lv_switch_create(parent);
    lv_obj_set_features(new_switch, 90, 40,
        LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_set_style_bg_color(new_switch, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(new_switch, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(new_switch, lv_color_hex(0x191D26), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(new_switch, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(new_switch, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(new_switch, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(new_switch, lv_color_hex(0x00D4FF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(new_switch, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_color(new_switch, lv_color_hex(0x0179FF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(new_switch, LV_GRAD_DIR_HOR, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(new_switch, lv_color_hex(0x191D26), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(new_switch, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(new_switch, 5, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_side(new_switch, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_bg_color(new_switch, lv_color_hex(0x7C92BA), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(new_switch, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(new_switch, lv_color_hex(0x536483), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(new_switch, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(new_switch, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(new_switch, LV_GRAD_DIR_VER, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(new_switch, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(new_switch, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(new_switch, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(new_switch, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(new_switch, lv_color_hex(0x00FEFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_opa(new_switch, 255, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(new_switch, 5, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_spread(new_switch, 0, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_ofs_x(new_switch, -3, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_ofs_y(new_switch, 0, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(new_switch, -5, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(new_switch, -5, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(new_switch, -5, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_pad_bottom(new_switch, -5, LV_PART_KNOB | LV_STATE_CHECKED);

    if (head_name != NULL)
    {
        lv_obj_add_flag(new_switch, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
        lv_obj_t* label = create_head_label(new_switch, head_name);
        lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, 25);
    }
    return new_switch;
}

lv_obj_t* create_slider(lv_obj_t* parent, int32_t min, int32_t max)
{
    lv_obj_t* new_slider = lv_slider_create(parent);
    lv_slider_set_range(new_slider, min, max);
    lv_slider_set_value(new_slider, 50, LV_ANIM_OFF);
    if (lv_slider_get_mode(new_slider) == LV_SLIDER_MODE_RANGE)
    {
        lv_slider_set_left_value(new_slider, 0, LV_ANIM_OFF);
    }
    lv_obj_set_features(new_slider, 475, 35, LV_ALIGN_CENTER, 0, 0);

    lv_obj_set_style_bg_color(new_slider, lv_color_hex(0x222733), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(new_slider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(new_slider, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(new_slider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(new_slider, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(new_slider, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(new_slider, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(new_slider, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(new_slider, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(new_slider, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(new_slider, lv_color_hex(0x1DE8FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(new_slider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(new_slider, lv_color_hex(0x0962B7), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(new_slider, LV_GRAD_DIR_HOR, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(new_slider, lv_color_hex(0x7689AC), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(new_slider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(new_slider, lv_color_hex(0x556483), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(new_slider, LV_GRAD_DIR_VER, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(new_slider, lv_color_hex(0x28DCFD), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(new_slider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(new_slider, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(new_slider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(new_slider, -2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(new_slider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(new_slider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(new_slider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(new_slider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(new_slider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    return new_slider;
}

lv_obj_t* create_statusbar(lv_obj_t* parent, const char* head_name)
{
    lv_obj_t* new_statusbar = lv_obj_create(parent);

    lv_obj_set_width(new_statusbar, 665);
    lv_obj_set_height(new_statusbar, 39);

    lv_obj_set_x(new_statusbar, -30);
    lv_obj_set_y(new_statusbar, 0);
    lv_obj_set_align(new_statusbar, LV_ALIGN_TOP_RIGHT);

    lv_obj_clear_flag(new_statusbar, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(new_statusbar, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(new_statusbar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(new_statusbar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(new_statusbar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(new_statusbar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    if (head_name != NULL)
    {
        lv_obj_t* label = create_head_label(new_statusbar, head_name);
        lv_obj_set_align(label, LV_ALIGN_LEFT_MID);
    }

    // ui_IMG_Wifi
    lv_obj_t* icon_wifi = create_icon(new_statusbar, &ui_img_icn_wifi_png);
    lv_obj_set_features(icon_wifi, LV_SIZE_CONTENT, LV_SIZE_CONTENT,
        LV_ALIGN_RIGHT_MID, 0, 0);
    // ui_IMG_PC
    lv_obj_t* icon_pc = create_icon(new_statusbar, &ui_img_icn_pc_png);
    lv_obj_set_features(icon_pc, LV_SIZE_CONTENT, LV_SIZE_CONTENT,
        LV_ALIGN_RIGHT_MID, -42, 0);
    // ui_IMG_USB
    lv_obj_t* icon_usb = create_icon(new_statusbar, &ui_img_icn_usb_png);
    lv_obj_set_features(icon_usb, LV_SIZE_CONTENT, LV_SIZE_CONTENT,
        LV_ALIGN_RIGHT_MID, -84, 0);
    return new_statusbar;
}
