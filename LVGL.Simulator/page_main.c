#include "models.h"

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
#error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
#error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

lv_obj_t* screen_obj;

void page_main_screen_init(void)
{
    screen_obj = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_obj, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(screen_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t* screen_bg = create_icon(screen_obj, &ui_img_3d_printer_bg_png);
    lv_obj_set_features(screen_bg, 800, 480, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t* statusbar = create_statusbar(screen_obj, "Base Demo");
}

void page_main_init(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
        false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    page_main_screen_init();

    lv_disp_load_scr(screen_obj);
}
