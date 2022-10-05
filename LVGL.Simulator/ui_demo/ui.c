// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: 3d_printer

#include "ui.h"
#include "ui_helpers.h"
#include "models.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen_1_Print;
lv_obj_t * ui_Background;
lv_obj_t * ui_Panel_Header;
lv_obj_t * ui_Label_Header;
lv_obj_t * ui_IMG_Wifi;
lv_obj_t * ui_IMG_PC;
lv_obj_t * ui_IMG_USB;
lv_obj_t * ui_BTN_Menu_Print_S1;
lv_obj_t * ui_BTN_Menu_Move_S1;
lv_obj_t * ui_BTN_Menu_Setting_S1;
lv_obj_t * ui_S1_Content_Panel;
lv_obj_t * ui_Slider_Print_View;
lv_obj_t * ui_Number_Print;
lv_obj_t * ui_Display_Time_S1;
lv_obj_t * ui_DT1;
lv_obj_t * ui_Label_Printing_Time_1;
lv_obj_t * ui_IMG_Tine_1;
lv_obj_t * ui_Label_Time_1;
lv_obj_t * ui_Panel3;
lv_obj_t * ui_DT2;
lv_obj_t * ui_Label_Printing_Time_2;
lv_obj_t * ui_IMG_Tine_2;
lv_obj_t * ui_Label_Time_2;
lv_obj_t * ui_Display_Heat_S1;
lv_obj_t * ui_DT3;
lv_obj_t * ui_Label_Printing_Head_Temp;
lv_obj_t * ui_IMG_Head;
lv_obj_t * ui_Label_Head_Temp;
lv_obj_t * ui_Label_Printing_Head_Temp_2;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_DT3_copy;
lv_obj_t * ui_Label_Printing_Bed_Temp;
lv_obj_t * ui_IMG_Head1;
lv_obj_t * ui_Label_Bed_Temp;
lv_obj_t * ui_Label_Printing_Bed_Temp1;
lv_obj_t * ui_Panel_Buttons_S1;
lv_obj_t * ui_BTN_Pause;
lv_obj_t * ui_BTN_Pause_Top;
lv_obj_t * ui_Image_Pause;
lv_obj_t * ui_BTN_Cancel;
lv_obj_t * ui_BTN_Cancel_Top;
lv_obj_t * ui_Image_Cancel;
lv_obj_t * ui_Screen_2_Move;
lv_obj_t * ui_Background1;
lv_obj_t * ui_Panel_Header1;
lv_obj_t * ui_Label_Header1;
lv_obj_t * ui_IMG_Wifi1;
lv_obj_t * ui_IMG_PC1;
lv_obj_t * ui_IMG_USB1;
lv_obj_t * ui_BTN_Menu_Print_S2;
lv_obj_t * ui_BTN_Menu_Move_S2;
lv_obj_t * ui_BTN_Menu_Setting_S2;
lv_obj_t * ui_S1_Content_Panel1;
lv_obj_t * ui_Display_Pos_XY;
lv_obj_t * ui_DP1;
lv_obj_t * ui_Label_X_Position;
lv_obj_t * ui_Label_X_Position_Number;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_DP2;
lv_obj_t * ui_Label_Y_Position;
lv_obj_t * ui_Label_Time_3;
lv_obj_t * ui_Display_Pos_y;
lv_obj_t * ui_DP3;
lv_obj_t * ui_Label_Z_Position;
lv_obj_t * ui_Label_Z_Position_Number;
lv_obj_t * ui_BTN_Move_Z;
lv_obj_t * ui_GLOW_1;
lv_obj_t * ui_GLOW_2;
lv_obj_t * ui_BTN_Image_Top;
lv_obj_t * ui_Label_Z_Position_2;
lv_obj_t * ui_Arrow_Z_up;
lv_obj_t * ui_Arrow_Z_Down;
lv_obj_t * ui_BTN_Move_XY;
lv_obj_t * ui_GLOW_3;
lv_obj_t * ui_GLOW_4;
lv_obj_t * ui_GLOW_5;
lv_obj_t * ui_GLOW_6;
lv_obj_t * ui_BTN_Move_XY_Top;
lv_obj_t * ui_Label_XY_Position;
lv_obj_t * ui_Arrow_Up_2;
lv_obj_t * ui_Arrow_Down_2;
lv_obj_t * ui_Arrow_Left_2;
lv_obj_t * ui_Arrow_Right_2;
lv_obj_t * ui_Roller_Number;
lv_obj_t * ui_Image8;
lv_obj_t * ui_Roller1;
lv_obj_t * ui_Label_Steps;
lv_obj_t * ui_BTN_Reset;
lv_obj_t * ui_Label_Reset;
lv_obj_t * ui_BTN_Heat;
lv_obj_t * ui_Label_Reset1;
lv_obj_t * ui_Screen_3_Setting;
lv_obj_t * ui_Background2;
lv_obj_t * ui_Panel_Header2;
lv_obj_t * ui_Label_Header2;
lv_obj_t * ui_IMG_Wifi2;
lv_obj_t * ui_IMG_PC2;
lv_obj_t * ui_IMG_USB2;
lv_obj_t * ui_BTN_Menu_Print_S3;
lv_obj_t * ui_BTN_Menu_Move_S3;
lv_obj_t * ui_BTN_Menu_Setting_S3;
lv_obj_t * ui_S1_Content_Panel2;
lv_obj_t * ui_Roller_Material;
lv_obj_t * ui_Image3;
lv_obj_t * ui_Roller4;
lv_obj_t * ui_Label_Material;
lv_obj_t * ui_Roller_Bed_Temp;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Roller3;
lv_obj_t * ui_Label_Bed_Temp1;
lv_obj_t * ui_Roller_Head_Temp;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Roller2;
lv_obj_t * ui_Label_Head_Temp1;
lv_obj_t * ui_BTN_Heat_Head;
lv_obj_t * ui_Label_Reset22;
lv_obj_t * ui_BTN_Heat_Bed;
lv_obj_t * ui_Label_Heat_Bed;
lv_obj_t * ui_BTN_Remove_Filament;
lv_obj_t * ui_Label_Remove_Filament;
lv_obj_t * ui_Panel_Slider;
lv_obj_t * ui_Slider_Print_Speed;
lv_obj_t * ui_Label_Print_Speed;
lv_obj_t * ui_Label_Print_Speed_Number;
lv_obj_t * ui_Swich_Group;
lv_obj_t * ui_Label_Light;
lv_obj_t * ui_Switch_Light;
lv_obj_t * ui_Label_Fan_1;
lv_obj_t * ui_Switch_Fan_1;
lv_obj_t * ui_Label_Fan_2;
lv_obj_t * ui_Switch_Fan_2;
lv_obj_t * ui_Label_Fan_3;
lv_obj_t * ui_Switch_Fan_3;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
// FUNCTION HEADER
void OpaOn_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void OpaOn_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 10);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
}

// FUNCTION HEADER
void OpaOff_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void OpaOff_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 255, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
}

// FUNCTION HEADER
void ScreenIn_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void ScreenIn_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 300);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);
}

// FUNCTION HEADER
void MenuIn_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void MenuIn_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

}

// FUNCTION HEADER
void MenuOut_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void MenuOut_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 150);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 255, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
}

//
// FUNCTION HEADER
void ScreenOut_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void ScreenOut_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 255, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////
static void ui_event_BTN_Menu_Move_S1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen_2_Move, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
static void ui_event_BTN_Menu_Setting_S1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen_3_Setting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
static void ui_event_Slider_Print_View(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        _ui_slider_set_text_value(ui_Number_Print, ta, "", "%");
    }
}
static void ui_event_BTN_Cancel_Top(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_BTN_Pause_Top, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}
static void ui_event_BTN_Menu_Print_S2(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen_1_Print, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
static void ui_event_BTN_Menu_Setting_S2(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen_3_Setting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
static void ui_event_GLOW_1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_PRESSED) {
        OpaOn_Animation(ui_GLOW_1, 0);
        _ui_state_modify(ui_Arrow_Z_up, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
    }
    if(event == LV_EVENT_RELEASED) {
        OpaOff_Animation(ui_GLOW_1, 0);
        _ui_state_modify(ui_Arrow_Z_up, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if(event == LV_EVENT_PRESS_LOST) {
        OpaOff_Animation(ui_GLOW_1, 0);
        _ui_state_modify(ui_Arrow_Z_up, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}
static void ui_event_GLOW_2(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_PRESSED) {
        OpaOn_Animation(ui_GLOW_2, 0);
        _ui_state_modify(ui_Arrow_Z_Down, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
    }
    if(event == LV_EVENT_RELEASED) {
        OpaOff_Animation(ui_GLOW_2, 0);
        _ui_state_modify(ui_Arrow_Z_Down, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if(event == LV_EVENT_PRESS_LOST) {
        OpaOff_Animation(ui_GLOW_2, 0);
        _ui_state_modify(ui_Arrow_Z_Down, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}
static void ui_event_GLOW_3(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_PRESSED) {
        OpaOn_Animation(ui_GLOW_3, 0);
        _ui_state_modify(ui_Arrow_Right_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
    }
    if(event == LV_EVENT_RELEASED) {
        OpaOff_Animation(ui_GLOW_3, 0);
        _ui_state_modify(ui_Arrow_Right_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if(event == LV_EVENT_PRESS_LOST) {
        OpaOff_Animation(ui_GLOW_3, 0);
        _ui_state_modify(ui_Arrow_Right_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}
static void ui_event_GLOW_4(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_PRESSED) {
        OpaOn_Animation(ui_GLOW_4, 0);
        _ui_state_modify(ui_Arrow_Up_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
    }
    if(event == LV_EVENT_RELEASED) {
        OpaOff_Animation(ui_GLOW_4, 0);
        _ui_state_modify(ui_Arrow_Up_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if(event == LV_EVENT_PRESS_LOST) {
        OpaOff_Animation(ui_GLOW_4, 0);
        _ui_state_modify(ui_Arrow_Up_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}
static void ui_event_GLOW_5(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_PRESSED) {
        OpaOn_Animation(ui_GLOW_5, 0);
        _ui_state_modify(ui_Arrow_Down_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
    }
    if(event == LV_EVENT_RELEASED) {
        OpaOff_Animation(ui_GLOW_5, 0);
        _ui_state_modify(ui_Arrow_Down_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if(event == LV_EVENT_PRESS_LOST) {
        OpaOff_Animation(ui_GLOW_5, 0);
        _ui_state_modify(ui_Arrow_Down_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}
static void ui_event_GLOW_6(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_PRESSED) {
        OpaOn_Animation(ui_GLOW_6, 0);
        _ui_state_modify(ui_Arrow_Left_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
    }
    if(event == LV_EVENT_RELEASED) {
        OpaOff_Animation(ui_GLOW_6, 0);
        _ui_state_modify(ui_Arrow_Left_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if(event == LV_EVENT_PRESS_LOST) {
        OpaOff_Animation(ui_GLOW_6, 0);
        _ui_state_modify(ui_Arrow_Left_2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}
static void ui_event_BTN_Menu_Print_S3(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen_1_Print, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
static void ui_event_BTN_Menu_Move_S3(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen_2_Move, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
static void ui_event_Slider_Print_Speed(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        _ui_slider_set_text_value(ui_Label_Print_Speed_Number, ta, "", "%");
    }
}

void obj_style_add_pad(lv_obj_t* obj)
{
    lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
}

///////////////////// SCREENS ////////////////////
void ui_Screen_1_Print_screen_init(void)
{
    // ui_Screen_1_Print
    ui_Screen_1_Print = lv_obj_create(NULL);

    lv_obj_set_style_bg_color(ui_Screen_1_Print, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_1_Print, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Background
    ui_Background = create_icon(ui_Screen_1_Print, &ui_img_3d_printer_bg_png);
    lv_obj_set_features(ui_Background, 800, 480, LV_ALIGN_CENTER, 0, 0);
    // ui_Panel_Header
    ui_Panel_Header = create_statusbar(ui_Screen_1_Print, "The #ffffff squareline.gcode# word file is being printed");

    // ui_BTN_Menu_Print_S1
    ui_BTN_Menu_Print_S1 = create_icon(ui_Screen_1_Print, &ui_img_btn_print_png);
    lv_obj_set_features(ui_BTN_Menu_Print_S1, 79, 160, LV_ALIGN_TOP_LEFT, 0, 0);

    lv_obj_add_flag(ui_BTN_Menu_Print_S1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui_BTN_Menu_Print_S1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_BTN_Menu_Move_S1
    ui_BTN_Menu_Move_S1 = create_icon(ui_Screen_1_Print, &ui_img_btn_move_png);
    lv_obj_set_features(ui_BTN_Menu_Move_S1, 79, 162,
                                            LV_ALIGN_LEFT_MID, 0, 0);

    lv_obj_add_flag(ui_BTN_Menu_Move_S1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_BTN_Menu_Move_S1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_BTN_Menu_Move_S1, ui_event_BTN_Menu_Move_S1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_opa(ui_BTN_Menu_Move_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_BTN_Menu_Setting_S1
    ui_BTN_Menu_Setting_S1 = create_icon(ui_Screen_1_Print, &ui_img_btn_setting_png);
    lv_obj_set_features(ui_BTN_Menu_Setting_S1, 79, 160,
                                                LV_ALIGN_BOTTOM_LEFT, 0, 0);

    lv_obj_add_flag(ui_BTN_Menu_Setting_S1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_BTN_Menu_Setting_S1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_BTN_Menu_Setting_S1, ui_event_BTN_Menu_Setting_S1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_opa(ui_BTN_Menu_Setting_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_S1_Content_Panel
    ui_S1_Content_Panel = create_base_obj(ui_Screen_1_Print, 720, 430);
    lv_obj_align(ui_S1_Content_Panel, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    // ui_Slider_Print_View
    ui_Slider_Print_View = lv_slider_create(ui_S1_Content_Panel);
    lv_slider_set_range(ui_Slider_Print_View, 0, 100);
    lv_slider_set_value(ui_Slider_Print_View, 70, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider_Print_View) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider_Print_View, 0,
                                                                                                      LV_ANIM_OFF);

    lv_obj_set_width(ui_Slider_Print_View, 332);
    lv_obj_set_height(ui_Slider_Print_View, 396);

    lv_obj_set_x(ui_Slider_Print_View, 0);
    lv_obj_set_y(ui_Slider_Print_View, -10);

    lv_obj_set_align(ui_Slider_Print_View, LV_ALIGN_LEFT_MID);

    lv_obj_add_event_cb(ui_Slider_Print_View, ui_event_Slider_Print_View, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_Slider_Print_View, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider_Print_View, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider_Print_View, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Slider_Print_View, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Slider_Print_View, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider_Print_View, &ui_img_print_view_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider_Print_View, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider_Print_View, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider_Print_View, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Slider_Print_View, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Slider_Print_View, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider_Print_View, &ui_img_print_view_front_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Slider_Print_View, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider_Print_View, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Number_Print
    ui_Number_Print = create_head_label(ui_Slider_Print_View, "70%");
    lv_obj_align(ui_Number_Print, LV_ALIGN_BOTTOM_MID, 0, -40);
    lv_obj_set_style_text_color(ui_Number_Print, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Number_Print, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Display_Time_S1
    ui_Display_Time_S1 = create_box(ui_S1_Content_Panel, 350, 79);
    lv_obj_align(ui_Display_Time_S1, LV_ALIGN_TOP_RIGHT, -26, 30);

    // ui_DT1
    ui_DT1 = create_base_obj(ui_Display_Time_S1, lv_pct(50), lv_pct(100));
    lv_obj_align(ui_DT1, LV_ALIGN_LEFT_MID, 0, 0);
    obj_style_add_pad(ui_DT1);

    // ui_Label_Printing_Time_1
    ui_Label_Printing_Time_1 = create_head_label(ui_DT1, "Printing Time");
    lv_obj_set_align(ui_Label_Printing_Time_1, LV_ALIGN_TOP_MID);
    lv_obj_set_style_text_color(ui_Label_Printing_Time_1, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_IMG_Tine_1
    ui_IMG_Tine_1 = lv_img_create(ui_DT1);
    lv_img_set_src(ui_IMG_Tine_1, &ui_img_icn_time_1_png);

    lv_obj_set_content(ui_IMG_Tine_1);

    lv_obj_set_x(ui_IMG_Tine_1, 20);
    lv_obj_set_y(ui_IMG_Tine_1, 10);

    lv_obj_set_align(ui_IMG_Tine_1, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_IMG_Tine_1, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_Label_Time_1
    ui_Label_Time_1 = create_head_label(ui_DT1, "10:52");
    lv_obj_align(ui_Label_Time_1, LV_ALIGN_LEFT_MID, 60, 10);
    lv_obj_set_style_text_color(ui_Label_Time_1, lv_color_hex(0xDBE6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Time_1, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Panel3
    ui_Panel3 = lv_obj_create(ui_Display_Time_S1);

    lv_obj_set_width(ui_Panel3, 2);
    lv_obj_set_height(ui_Panel3, 50);

    lv_obj_center(ui_Panel3);

    lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0x3A3F4B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_DT2

    ui_DT2 = create_base_obj(ui_Display_Time_S1, lv_pct(50), lv_pct(100));
    lv_obj_align(ui_DT2, LV_ALIGN_RIGHT_MID, 0, 0);
    obj_style_add_pad(ui_DT2);

    // ui_Label_Printing_Time_2
    ui_Label_Printing_Time_2 = create_head_label(ui_DT2, "Printing Time");
    lv_obj_set_align(ui_Label_Printing_Time_2, LV_ALIGN_TOP_MID);
    lv_obj_set_style_text_color(ui_Label_Printing_Time_2, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_IMG_Tine_2
    ui_IMG_Tine_2 = lv_img_create(ui_DT2);
    lv_img_set_src(ui_IMG_Tine_2, &ui_img_icn_time_2_png);

    lv_obj_set_content(ui_IMG_Tine_2);

    lv_obj_set_x(ui_IMG_Tine_2, 20);
    lv_obj_set_y(ui_IMG_Tine_2, 10);

    lv_obj_set_align(ui_IMG_Tine_2, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_IMG_Tine_2, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_Label_Time_2

    ui_Label_Time_2 = create_head_label(ui_DT2, "08:25");
    lv_obj_align(ui_Label_Time_2, LV_ALIGN_LEFT_MID, 60, 10);
    lv_obj_set_style_text_font(ui_Label_Time_2, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Display_Heat_S1

    ui_Display_Heat_S1 = create_box(ui_S1_Content_Panel, 350, 79);
    lv_obj_align(ui_Display_Heat_S1, LV_ALIGN_TOP_RIGHT, -26, 130);

    // ui_DT3
    ui_DT3 = create_base_obj(ui_Display_Heat_S1, lv_pct(50), lv_pct(100));
    lv_obj_align(ui_DT3, LV_ALIGN_LEFT_MID, 0, 0);
    obj_style_add_pad(ui_DT3);

    // ui_Label_Printing_Head_Temp
    ui_Label_Printing_Head_Temp = create_head_label(ui_DT3, "Head Temp.");
    lv_obj_set_align(ui_Label_Printing_Head_Temp, LV_ALIGN_TOP_MID);
    lv_obj_set_style_text_color(ui_Label_Printing_Head_Temp, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_IMG_Head
    ui_IMG_Head = lv_img_create(ui_DT3);
    lv_img_set_src(ui_IMG_Head, &ui_img_icn_head_png);

    lv_obj_set_content(ui_IMG_Head);

    lv_obj_set_x(ui_IMG_Head, 15);
    lv_obj_set_y(ui_IMG_Head, 10);

    lv_obj_set_align(ui_IMG_Head, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_IMG_Head, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_Label_Head_Temp
    ui_Label_Head_Temp = create_head_label(ui_DT3, "195°");
    lv_obj_align(ui_Label_Head_Temp, LV_ALIGN_LEFT_MID, 40, 10);

    lv_obj_set_style_text_color(ui_Label_Head_Temp, lv_color_hex(0xDBE6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Head_Temp, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Printing_Head_Temp_2
    ui_Label_Printing_Head_Temp_2 = create_head_label(ui_DT3, "/ 195°");
    lv_obj_align(ui_Label_Printing_Head_Temp_2, LV_ALIGN_LEFT_MID, 95, 13);
    lv_obj_set_style_text_color(ui_Label_Printing_Head_Temp_2, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Panel1
    ui_Panel1 = lv_obj_create(ui_Display_Heat_S1);

    lv_obj_set_width(ui_Panel1, 2);
    lv_obj_set_height(ui_Panel1, 50);

    lv_obj_center(ui_Panel1);

    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x3A3F4B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_DT3_copy

    ui_DT3_copy = create_base_obj(ui_Display_Heat_S1, lv_pct(50), lv_pct(100));
    lv_obj_align(ui_DT3_copy, LV_ALIGN_RIGHT_MID, 0, 0);
    obj_style_add_pad(ui_DT3_copy);

    // ui_Label_Printing_Bed_Temp
    ui_Label_Printing_Bed_Temp = create_head_label(ui_DT3_copy, "Bed Temp.");
    lv_obj_set_align(ui_Label_Printing_Bed_Temp, LV_ALIGN_TOP_MID);
    lv_obj_set_style_text_color(ui_Label_Printing_Bed_Temp, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_IMG_Head1
    ui_IMG_Head1 = lv_img_create(ui_DT3_copy);
    lv_img_set_src(ui_IMG_Head1, &ui_img_icn_bed_png);

    lv_obj_set_content(ui_IMG_Head1);

    lv_obj_set_x(ui_IMG_Head1, 20);
    lv_obj_set_y(ui_IMG_Head1, 10);

    lv_obj_set_align(ui_IMG_Head1, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_IMG_Head1, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_Label_Bed_Temp

    ui_Label_Bed_Temp = create_head_label(ui_DT3_copy, "65°");
    lv_obj_align(ui_Label_Bed_Temp, LV_ALIGN_LEFT_MID, 55, 10);
    lv_obj_set_style_text_color(ui_Label_Bed_Temp, lv_color_hex(0xDBE6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Bed_Temp, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Printing_Bed_Temp1
    ui_Label_Printing_Bed_Temp1 = create_head_label(ui_DT3_copy, "/ 65°");
    lv_obj_align(ui_Label_Printing_Bed_Temp1, LV_ALIGN_LEFT_MID, 100, 13);
    lv_obj_set_style_text_color(ui_Label_Printing_Bed_Temp1, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Panel_Buttons_S1
    ui_Panel_Buttons_S1 = create_base_obj(ui_S1_Content_Panel, 380, 200);
    lv_obj_set_align(ui_Panel_Buttons_S1, LV_ALIGN_BOTTOM_RIGHT);

    // ui_BTN_Pause

    ui_BTN_Pause = lv_img_create(ui_Panel_Buttons_S1);
    lv_img_set_src(ui_BTN_Pause, &ui_img_btn_print_down_png);

    lv_obj_set_content(ui_BTN_Pause);

    lv_obj_set_x(ui_BTN_Pause, 10);
    lv_obj_set_y(ui_BTN_Pause, 0);

    lv_obj_set_align(ui_BTN_Pause, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_BTN_Pause, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_BTN_Pause_Top

    ui_BTN_Pause_Top = lv_img_create(ui_BTN_Pause);
    lv_img_set_src(ui_BTN_Pause_Top, &ui_img_btn_print_top_off_png);

    lv_obj_set_content(ui_BTN_Pause_Top);

    lv_obj_center(ui_BTN_Pause_Top);

    lv_obj_add_flag(ui_BTN_Pause_Top, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST);

    lv_obj_set_style_radius(ui_BTN_Pause_Top, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_BTN_Pause_Top, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_BTN_Pause_Top, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_BTN_Pause_Top, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_opa(ui_BTN_Pause_Top, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui_BTN_Pause_Top, 9, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_spread(ui_BTN_Pause_Top, 3, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_ofs_x(ui_BTN_Pause_Top, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_ofs_y(ui_BTN_Pause_Top, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_color(ui_BTN_Pause_Top, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_BTN_Pause_Top, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_BTN_Pause_Top, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_BTN_Pause_Top, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_ofs_x(ui_BTN_Pause_Top, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_ofs_y(ui_BTN_Pause_Top, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor(ui_BTN_Pause_Top, lv_color_hex(0x67799B), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui_BTN_Pause_Top, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    // ui_Image_Pause
    ui_Image_Pause = lv_img_create(ui_BTN_Pause_Top);
    lv_img_set_src(ui_Image_Pause, &ui_img_icn_pause_png);

    lv_obj_set_content(ui_Image_Pause);

    lv_obj_center(ui_Image_Pause);

    lv_obj_add_flag(ui_Image_Pause, LV_OBJ_FLAG_ADV_HITTEST);

    lv_obj_set_style_img_recolor(ui_Image_Pause, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image_Pause, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_BTN_Cancel

    ui_BTN_Cancel = lv_img_create(ui_Panel_Buttons_S1);
    lv_img_set_src(ui_BTN_Cancel, &ui_img_btn_print_down_png);

    lv_obj_set_content(ui_BTN_Cancel);

    lv_obj_set_x(ui_BTN_Cancel, -30);
    lv_obj_set_y(ui_BTN_Cancel, 0);

    lv_obj_set_align(ui_BTN_Cancel, LV_ALIGN_RIGHT_MID);

    lv_obj_add_flag(ui_BTN_Cancel, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_BTN_Cancel_Top

    ui_BTN_Cancel_Top = lv_img_create(ui_BTN_Cancel);
    lv_img_set_src(ui_BTN_Cancel_Top, &ui_img_btn_print_top_off_png);

    lv_obj_set_content(ui_BTN_Cancel_Top);

    lv_obj_center(ui_BTN_Cancel_Top);

    lv_obj_add_flag(ui_BTN_Cancel_Top, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);

    lv_obj_add_event_cb(ui_BTN_Cancel_Top, ui_event_BTN_Cancel_Top, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_BTN_Cancel_Top, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_BTN_Cancel_Top, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_BTN_Cancel_Top, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_BTN_Cancel_Top, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_opa(ui_BTN_Cancel_Top, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui_BTN_Cancel_Top, 9, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_spread(ui_BTN_Cancel_Top, 3, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_ofs_x(ui_BTN_Cancel_Top, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_ofs_y(ui_BTN_Cancel_Top, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_color(ui_BTN_Cancel_Top, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_BTN_Cancel_Top, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_BTN_Cancel_Top, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_BTN_Cancel_Top, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor(ui_BTN_Cancel_Top, lv_color_hex(0x67799B), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui_BTN_Cancel_Top, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    // ui_Image_Cancel
    ui_Image_Cancel = create_icon(ui_BTN_Cancel_Top, &ui_img_icn_stop_png);
    lv_obj_set_features(ui_Image_Cancel, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER, 0, 0);

    lv_obj_set_style_img_recolor(ui_Image_Cancel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image_Cancel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}
void ui_Screen_2_Move_screen_init(void)
{
    // ui_Screen_2_Move
    ui_Screen_2_Move = lv_obj_create(NULL);

    lv_obj_set_style_bg_color(ui_Screen_2_Move, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_2_Move, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Background1
    ui_Background1 = create_icon(ui_Screen_2_Move, &ui_img_3d_printer_bg_png);
    lv_obj_set_features(ui_Background, 800, 480, LV_ALIGN_CENTER, 0, 0);

    // ui_Panel_Header1
    ui_Panel_Header1 = create_statusbar(ui_Screen_2_Move, "Press the control buttons to move the tray and head");

    // ui_BTN_Menu_Print_S2
    ui_BTN_Menu_Print_S2 = lv_img_create(ui_Screen_2_Move);
    lv_img_set_src(ui_BTN_Menu_Print_S2, &ui_img_btn_print_png);

    lv_obj_set_width(ui_BTN_Menu_Print_S2, 79);
    lv_obj_set_height(ui_BTN_Menu_Print_S2, 160);

    lv_obj_set_x(ui_BTN_Menu_Print_S2, 0);
    lv_obj_set_y(ui_BTN_Menu_Print_S2, 0);

    lv_obj_add_flag(ui_BTN_Menu_Print_S2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_BTN_Menu_Print_S2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_BTN_Menu_Print_S2, ui_event_BTN_Menu_Print_S2, LV_EVENT_ALL, NULL);
    lv_obj_set_style_opa(ui_BTN_Menu_Print_S2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_BTN_Menu_Move_S2

    ui_BTN_Menu_Move_S2 = lv_img_create(ui_Screen_2_Move);
    lv_img_set_src(ui_BTN_Menu_Move_S2, &ui_img_btn_move_png);

    lv_obj_set_width(ui_BTN_Menu_Move_S2, 79);
    lv_obj_set_height(ui_BTN_Menu_Move_S2, 162);

    lv_obj_set_x(ui_BTN_Menu_Move_S2, 0);
    lv_obj_set_y(ui_BTN_Menu_Move_S2, 0);

    lv_obj_set_align(ui_BTN_Menu_Move_S2, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_BTN_Menu_Move_S2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_BTN_Menu_Move_S2, LV_OBJ_FLAG_SCROLLABLE);

    // ui_BTN_Menu_Setting_S2 
    ui_BTN_Menu_Setting_S2 = lv_img_create(ui_Screen_2_Move);
    lv_img_set_src(ui_BTN_Menu_Setting_S2, &ui_img_btn_setting_png);

    lv_obj_set_width(ui_BTN_Menu_Setting_S2, 79);
    lv_obj_set_height(ui_BTN_Menu_Setting_S2, 160);

    lv_obj_set_pos(ui_BTN_Menu_Setting_S2, 0, 0);

    lv_obj_set_align(ui_BTN_Menu_Setting_S2, LV_ALIGN_BOTTOM_LEFT);

    lv_obj_add_flag(ui_BTN_Menu_Setting_S2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_BTN_Menu_Setting_S2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_BTN_Menu_Setting_S2, ui_event_BTN_Menu_Setting_S2, LV_EVENT_ALL, NULL);
    lv_obj_set_style_opa(ui_BTN_Menu_Setting_S2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_S1_Content_Panel1
    ui_S1_Content_Panel1 = create_base_obj(ui_Screen_2_Move, 720, 430);
    lv_obj_set_align(ui_S1_Content_Panel1, LV_ALIGN_BOTTOM_RIGHT);

    // ui_Display_Pos_XY
    ui_Display_Pos_XY = create_box(ui_S1_Content_Panel1, 283, 79);
    lv_obj_set_pos(ui_Display_Pos_XY, 200, 21);
    lv_obj_clear_flag(ui_Display_Pos_XY, LV_OBJ_FLAG_SCROLLABLE);

    // ui_DP1
    ui_DP1 = create_base_obj(ui_Display_Pos_XY, lv_pct(50), lv_pct(100));
    lv_obj_set_align(ui_DP1, LV_ALIGN_LEFT_MID);
    obj_style_add_pad(ui_DP1);

    // ui_Label_X_Position
    ui_Label_X_Position = create_head_label(ui_DP1, "X Position");
    lv_obj_set_align(ui_Label_X_Position, LV_ALIGN_TOP_MID);

    // ui_Label_X_Position_Number
    ui_Label_X_Position_Number = create_head_label(ui_DP1, "185");
    lv_obj_set_y(ui_Label_X_Position_Number, 10);
    lv_obj_set_style_text_font(ui_Label_X_Position_Number, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Panel2

    ui_Panel2 = lv_obj_create(ui_Display_Pos_XY);

    lv_obj_set_width(ui_Panel2, 2);
    lv_obj_set_height(ui_Panel2, 50);
    lv_obj_center(ui_Panel2);

    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x3A3F4B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_DP2
    ui_DP2 = create_base_obj(ui_Display_Pos_XY, lv_pct(50), lv_pct(100));
    lv_obj_set_align(ui_DP2, LV_ALIGN_RIGHT_MID);
    obj_style_add_pad(ui_DP2);

    // ui_Label_Y_Position
    ui_Label_Y_Position = create_head_label(ui_DP2, "Y Position");
    lv_obj_set_align(ui_Label_Y_Position, LV_ALIGN_TOP_MID);

    ui_Label_Time_3 = create_head_label(ui_DP2, "335");
    lv_obj_set_y(ui_Label_Time_3, 10);
    lv_obj_set_style_text_font(ui_Label_Time_3, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Display_Pos_y
    ui_Display_Pos_y = create_box(ui_S1_Content_Panel1, 133, 79);
    lv_obj_set_pos(ui_Display_Pos_y, 20, 21);
    lv_obj_clear_flag(ui_Display_Pos_y, LV_OBJ_FLAG_SCROLLABLE);

    // ui_DP3
    ui_DP3 = create_base_obj(ui_Display_Pos_y, lv_pct(100), lv_pct(100));
    lv_obj_set_align(ui_DP3, LV_ALIGN_RIGHT_MID);
    obj_style_add_pad(ui_DP3);

    // ui_Label_Z_Position
    ui_Label_Z_Position = create_head_label(ui_DP3, "Z Position");
    lv_obj_set_align(ui_Label_Z_Position, LV_ALIGN_TOP_MID);

    ui_Label_Z_Position_Number = create_head_label(ui_DP3, "465");
    lv_obj_set_y(ui_Label_Z_Position_Number, 10);
    lv_obj_set_style_text_font(ui_Label_Z_Position_Number, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_BTN_Move_Z
    ui_BTN_Move_Z = lv_img_create(ui_S1_Content_Panel1);
    lv_img_set_src(ui_BTN_Move_Z, &ui_img_btn_z_botton_png);

    lv_obj_set_width(ui_BTN_Move_Z, 140);
    lv_obj_set_height(ui_BTN_Move_Z, 312);

    lv_obj_set_x(ui_BTN_Move_Z, -273);
    lv_obj_set_y(ui_BTN_Move_Z, 45);

    lv_obj_set_align(ui_BTN_Move_Z, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_BTN_Move_Z, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_GLOW_1
    ui_GLOW_1 = create_glow(ui_BTN_Move_Z, 75, 70);
    lv_obj_align(ui_GLOW_1, LV_ALIGN_TOP_MID, 0, 34);
    lv_obj_add_event_cb(ui_GLOW_1, ui_event_GLOW_1, LV_EVENT_ALL, NULL);

    // ui_GLOW_2
    ui_GLOW_2 = create_glow(ui_BTN_Move_Z, 75, 70);
    lv_obj_align(ui_GLOW_2, LV_ALIGN_TOP_MID, 0, 211);
    lv_obj_add_event_cb(ui_GLOW_2, ui_event_GLOW_2, LV_EVENT_ALL, NULL);

    // ui_BTN_Image_Top

    ui_BTN_Image_Top = lv_img_create(ui_BTN_Move_Z);
    lv_img_set_src(ui_BTN_Image_Top, &ui_img_btn_z_top_png);

    lv_obj_set_content(ui_BTN_Image_Top);

    lv_obj_center(ui_BTN_Image_Top);

    lv_obj_add_flag(ui_BTN_Image_Top, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_Label_Z_Position_2

    ui_Label_Z_Position_2 = lv_label_create(ui_BTN_Image_Top);

    lv_obj_set_content(ui_Label_Z_Position_2);

    lv_obj_center(ui_Label_Z_Position_2);

    lv_label_set_text(ui_Label_Z_Position_2, "MOVE\nZ");
    lv_label_set_recolor(ui_Label_Z_Position_2, "true");

    lv_obj_set_style_text_color(ui_Label_Z_Position_2, lv_color_hex(0xABC1ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Z_Position_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_Z_Position_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Z_Position_2, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Arrow_Z_up

    ui_Arrow_Z_up = lv_img_create(ui_BTN_Image_Top);
    lv_img_set_src(ui_Arrow_Z_up, &ui_img_arrow_up_png);

    lv_obj_set_content(ui_Arrow_Z_up);

    lv_obj_set_x(ui_Arrow_Z_up, 0);
    lv_obj_set_y(ui_Arrow_Z_up, 20);

    lv_obj_set_align(ui_Arrow_Z_up, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Arrow_Z_up, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_img_recolor(ui_Arrow_Z_up, lv_color_hex(0xABC1ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Z_up, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Arrow_Z_up, lv_color_hex(0x00D1FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Z_up, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor(ui_Arrow_Z_up, lv_color_hex(0x00D1FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Z_up, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    // ui_Arrow_Z_Down

    ui_Arrow_Z_Down = lv_img_create(ui_BTN_Image_Top);
    lv_img_set_src(ui_Arrow_Z_Down, &ui_img_arrow_down_png);

    lv_obj_set_content(ui_Arrow_Z_Down);

    lv_obj_set_x(ui_Arrow_Z_Down, 0);
    lv_obj_set_y(ui_Arrow_Z_Down, -20);

    lv_obj_set_align(ui_Arrow_Z_Down, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_Arrow_Z_Down, LV_OBJ_FLAG_ADV_HITTEST);

    lv_obj_set_style_img_recolor(ui_Arrow_Z_Down, lv_color_hex(0xABC1ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Z_Down, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Arrow_Z_Down, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Z_Down, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    // ui_BTN_Move_XY

    ui_BTN_Move_XY = lv_img_create(ui_S1_Content_Panel1);
    lv_img_set_src(ui_BTN_Move_XY, &ui_img_btn_pad_bottom_png);

    lv_obj_set_content(ui_BTN_Move_XY);

    lv_obj_set_x(ui_BTN_Move_XY, -15);
    lv_obj_set_y(ui_BTN_Move_XY, 40);

    lv_obj_set_align(ui_BTN_Move_XY, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_BTN_Move_XY, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_GLOW_3
    ui_GLOW_3 = create_glow(ui_BTN_Move_XY, 120, 120);
    lv_obj_align(ui_GLOW_3, LV_ALIGN_TOP_MID, 64, 97);
    lv_obj_add_event_cb(ui_GLOW_3, ui_event_GLOW_3, LV_EVENT_ALL, NULL);

    // ui_GLOW_4
    ui_GLOW_4 = create_glow(ui_BTN_Move_XY, 120, 120);
    lv_obj_align(ui_GLOW_4, LV_ALIGN_TOP_MID, 1, 33);
    lv_obj_add_event_cb(ui_GLOW_4, ui_event_GLOW_4, LV_EVENT_ALL, NULL);


    // ui_GLOW_5
    ui_GLOW_5 = create_glow(ui_BTN_Move_XY, 120, 120);
    lv_obj_align(ui_GLOW_5, LV_ALIGN_TOP_MID, 0, 158);
    lv_obj_add_event_cb(ui_GLOW_5, ui_event_GLOW_5, LV_EVENT_ALL, NULL);

    // ui_GLOW_6
    ui_GLOW_6 = create_glow(ui_BTN_Move_XY, 120, 120);
    lv_obj_align(ui_GLOW_6, LV_ALIGN_TOP_MID, -64, 96);
    lv_obj_add_event_cb(ui_GLOW_6, ui_event_GLOW_6, LV_EVENT_ALL, NULL);

    // ui_BTN_Move_XY_Top

    ui_BTN_Move_XY_Top = lv_img_create(ui_BTN_Move_XY);
    lv_img_set_src(ui_BTN_Move_XY_Top, &ui_img_btn_pad_top_png);

    lv_obj_set_content(ui_BTN_Move_XY_Top);

    lv_obj_center(ui_BTN_Move_XY_Top);

    lv_obj_add_flag(ui_BTN_Move_XY_Top, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_Label_XY_Position

    ui_Label_XY_Position = lv_label_create(ui_BTN_Move_XY_Top);

    lv_obj_set_content(ui_Label_XY_Position);

    lv_obj_center(ui_Label_XY_Position);

    lv_label_set_text(ui_Label_XY_Position, "MOVE\nXY");
    lv_label_set_recolor(ui_Label_XY_Position, "true");

    lv_obj_set_style_text_color(ui_Label_XY_Position, lv_color_hex(0xABC1ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_XY_Position, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_XY_Position, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_XY_Position, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Arrow_Up_2

    ui_Arrow_Up_2 = lv_img_create(ui_BTN_Move_XY_Top);
    lv_img_set_src(ui_Arrow_Up_2, &ui_img_arrow_up_png);

    lv_obj_set_content(ui_Arrow_Up_2);

    lv_obj_set_x(ui_Arrow_Up_2, 0);
    lv_obj_set_y(ui_Arrow_Up_2, 25);

    lv_obj_set_align(ui_Arrow_Up_2, LV_ALIGN_TOP_MID);

    lv_obj_add_flag(ui_Arrow_Up_2, LV_OBJ_FLAG_ADV_HITTEST);

    lv_obj_set_style_img_recolor(ui_Arrow_Up_2, lv_color_hex(0xABC1ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Up_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Arrow_Up_2, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Up_2, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    // ui_Arrow_Down_2

    ui_Arrow_Down_2 = lv_img_create(ui_BTN_Move_XY_Top);
    lv_img_set_src(ui_Arrow_Down_2, &ui_img_arrow_down_png);

    lv_obj_set_content(ui_Arrow_Down_2);

    lv_obj_set_x(ui_Arrow_Down_2, 0);
    lv_obj_set_y(ui_Arrow_Down_2, -25);

    lv_obj_set_align(ui_Arrow_Down_2, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_Arrow_Down_2, LV_OBJ_FLAG_ADV_HITTEST);

    lv_obj_set_style_img_recolor(ui_Arrow_Down_2, lv_color_hex(0xABC1ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Down_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Arrow_Down_2, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Down_2, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    // ui_Arrow_Left_2
    ui_Arrow_Left_2 = lv_img_create(ui_BTN_Move_XY_Top);
    lv_img_set_src(ui_Arrow_Left_2, &ui_img_arrow_left_png);

    lv_obj_set_content(ui_Arrow_Left_2);

    lv_obj_set_x(ui_Arrow_Left_2, 25);
    lv_obj_set_y(ui_Arrow_Left_2, 0);

    lv_obj_set_align(ui_Arrow_Left_2, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_Arrow_Left_2, LV_OBJ_FLAG_ADV_HITTEST);

    lv_obj_set_style_img_recolor(ui_Arrow_Left_2, lv_color_hex(0xABC1ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Left_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Arrow_Left_2, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Left_2, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    // ui_Arrow_Right_2

    ui_Arrow_Right_2 = lv_img_create(ui_BTN_Move_XY_Top);
    lv_img_set_src(ui_Arrow_Right_2, &ui_img_arrow_right_png);

    lv_obj_set_content(ui_Arrow_Right_2);

    lv_obj_set_x(ui_Arrow_Right_2, -25);
    lv_obj_set_y(ui_Arrow_Right_2, 0);

    lv_obj_set_align(ui_Arrow_Right_2, LV_ALIGN_RIGHT_MID);

    lv_obj_add_flag(ui_Arrow_Right_2, LV_OBJ_FLAG_ADV_HITTEST);

    lv_obj_set_style_img_recolor(ui_Arrow_Right_2, lv_color_hex(0xABC1ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Right_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Arrow_Right_2, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(ui_Arrow_Right_2, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    // ui_Roller_Number
    ui_Roller_Number = create_base_obj(ui_S1_Content_Panel1, LV_SIZE_CONTENT, 215);
    lv_obj_align(ui_Roller_Number, LV_ALIGN_CENTER, 238, 86);

    // ui_Image8
    ui_Image8 = lv_img_create(ui_Roller_Number);
    lv_img_set_src(ui_Image8, &ui_img_roller_bg_png);
    lv_obj_set_content(ui_Image8);
    lv_obj_center(ui_Image8);
    lv_obj_add_flag(ui_Image8, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_Roller1
    ui_Roller1 = create_roller(ui_Roller_Number, "STEPS SIZE", "1\n5\n10\n15\n25\n50");

    // ui_BTN_Reset
    ui_BTN_Reset = create_btn(ui_S1_Content_Panel1, "RESET POS.");
    lv_obj_clear_flag(ui_BTN_Reset, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_align(ui_BTN_Reset, LV_ALIGN_TOP_RIGHT, -40, 20);

    // ui_BTN_Heat
    ui_BTN_Heat = create_btn(ui_S1_Content_Panel1, "HEAT");
    lv_obj_align(ui_BTN_Heat, LV_ALIGN_TOP_RIGHT, -40, 100);
}

void ui_Screen_3_Setting_screen_init(void)
{
    // ui_Screen_3_Setting
    ui_Screen_3_Setting = lv_obj_create(NULL);

    lv_obj_set_style_bg_color(ui_Screen_3_Setting, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_3_Setting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Background2
    ui_Background2 = create_icon(ui_Screen_3_Setting, &ui_img_3d_printer_bg_png);
    lv_obj_set_features(ui_Background, 800, 480, LV_ALIGN_CENTER, 0, 0);

    // ui_Panel_Header2
    ui_Panel_Header2 = create_statusbar(ui_Screen_3_Setting, "This is Status bar");

    // ui_BTN_Menu_Print_S3
    ui_BTN_Menu_Print_S3 = create_base_obj(ui_Screen_3_Setting, 79, 160);
    lv_obj_add_event_cb(ui_BTN_Menu_Print_S3, ui_event_BTN_Menu_Print_S3, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_img_src(ui_BTN_Menu_Print_S3, &ui_img_btn_print_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_BTN_Menu_Print_S3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_BTN_Menu_Move_S3
    ui_BTN_Menu_Move_S3 = create_base_obj(ui_Screen_3_Setting, 79, 160);
    lv_obj_set_align(ui_BTN_Menu_Move_S3, LV_ALIGN_LEFT_MID);
    lv_obj_add_event_cb(ui_BTN_Menu_Move_S3, ui_event_BTN_Menu_Move_S3, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_img_src(ui_BTN_Menu_Move_S3, &ui_img_btn_move_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_BTN_Menu_Move_S3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_BTN_Menu_Setting_S3

    ui_BTN_Menu_Setting_S3 = lv_obj_create(ui_Screen_3_Setting);

    lv_obj_set_width(ui_BTN_Menu_Setting_S3, 79);
    lv_obj_set_height(ui_BTN_Menu_Setting_S3, 160);

    lv_obj_set_x(ui_BTN_Menu_Setting_S3, 0);
    lv_obj_set_y(ui_BTN_Menu_Setting_S3, 0);

    lv_obj_set_align(ui_BTN_Menu_Setting_S3, LV_ALIGN_BOTTOM_LEFT);

    lv_obj_clear_flag(ui_BTN_Menu_Setting_S3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_main_stop(ui_BTN_Menu_Setting_S3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_BTN_Menu_Setting_S3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_BTN_Menu_Setting_S3, &ui_img_btn_setting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BTN_Menu_Setting_S3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_S1_Content_Panel2
    ui_S1_Content_Panel2 = create_base_obj(ui_Screen_3_Setting, 720, 430);
    lv_obj_set_align(ui_S1_Content_Panel2, LV_ALIGN_BOTTOM_RIGHT);

    // ui_Roller_Material
    ui_Roller_Material = create_base_obj(ui_S1_Content_Panel2, LV_SIZE_CONTENT, 215);
    lv_obj_set_pos(ui_Roller_Material, 350, 20);

    // ui_Image3
    ui_Image3 = lv_img_create(ui_Roller_Material);
    lv_img_set_src(ui_Image3, &ui_img_roller_bg_png);

    lv_obj_set_content(ui_Image3);
    lv_obj_center(ui_Image3);

    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_Roller4
    ui_Roller4 = create_roller(ui_Roller_Material, "MATERIAL", "ABS\nPLA\nPETC");

    // ui_Roller_Bed_Temp
    ui_Roller_Bed_Temp = create_base_obj(ui_S1_Content_Panel2, LV_SIZE_CONTENT, 215);
    lv_obj_set_pos(ui_Roller_Bed_Temp, 175, 20);

    // ui_Image2
    ui_Image2 = lv_img_create(ui_Roller_Bed_Temp);
    lv_img_set_src(ui_Image2, &ui_img_roller_bg_png);

    lv_obj_set_content(ui_Image2);
    lv_obj_center(ui_Image2);

    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);

    // ui_Roller3
    ui_Roller3 = create_roller(ui_Roller_Bed_Temp, "BED TEMP.", "50°\n55°\n60°\n65°\n70°\n75°\n80°\n90°");

    // ui_Roller_Head_Temp
    ui_Roller_Head_Temp = create_base_obj(ui_S1_Content_Panel2, LV_SIZE_CONTENT, 215);
    lv_obj_set_pos(ui_Roller_Head_Temp,  0, 20);

    // ui_Image1
    ui_Image1 = create_icon(ui_Roller_Head_Temp, &ui_img_roller_bg_png);
    lv_obj_set_content(ui_Image1);
    lv_obj_center(ui_Image1);

    // ui_Roller2
    ui_Roller2 = create_roller(ui_Roller_Head_Temp, "HEAD TEMP.", "160°\n170°\n180°\n190°\n200°\n210°\n220°\n230°");

    // ui_BTN_Heat_Head
    ui_BTN_Heat_Head = create_btn(ui_S1_Content_Panel2, "HEAT HEAD");
    lv_obj_set_pos(ui_BTN_Heat_Head, 12, 40);

    // ui_BTN_Heat_Bed
    ui_BTN_Heat_Bed = create_btn(ui_S1_Content_Panel2, "HEAT BED");
    lv_obj_set_pos(ui_BTN_Heat_Bed, 185, 40);

    // ui_BTN_Remove_Filament
    ui_BTN_Remove_Filament = create_btn(ui_S1_Content_Panel2, "REMOVE\nFILAMENT");
    lv_obj_set_pos(ui_BTN_Remove_Filament, 360, 40);

    // ui_Panel_Slider
    ui_Panel_Slider = create_base_obj(ui_S1_Content_Panel2, 550, 121);
    lv_obj_set_align(ui_Panel_Slider, LV_ALIGN_BOTTOM_LEFT);

    // ui_Slider_Print_Speed
    ui_Slider_Print_Speed = create_slider(ui_Panel_Slider, 0, 100);
    lv_obj_add_event_cb(ui_Slider_Print_Speed, ui_event_Slider_Print_Speed, LV_EVENT_ALL, NULL);

    // ui_Label_Print_Speed
    ui_Label_Print_Speed = create_head_label(ui_Panel_Slider, "PRIT SPEED");
    lv_obj_align(ui_Label_Print_Speed, LV_ALIGN_TOP_LEFT, 25, -10);

    // ui_Label_Print_Speed_Number
    ui_Label_Print_Speed_Number = create_head_label(ui_Panel_Slider, "50%");
    lv_obj_align(ui_Label_Print_Speed_Number, LV_ALIGN_TOP_RIGHT, -30, -10);

    // ui_Swich_Group
    ui_Swich_Group = create_group(ui_Screen_3_Setting, "MATERIAL");
    lv_obj_set_pos(ui_Swich_Group, -20, 50);

    // ui_Switch_Light
    ui_Switch_Light = create_switch(ui_Swich_Group, "Light");
    lv_obj_align(ui_Switch_Light, LV_ALIGN_TOP_MID, 0, 30);

    // ui_Switch_Fan_1
    ui_Switch_Fan_1 = create_switch(ui_Swich_Group, "FAN 1");
    lv_obj_align(ui_Switch_Fan_1, LV_ALIGN_TOP_MID, 0, 130);

    // ui_Switch_Fan_2
    ui_Switch_Fan_2 = create_switch(ui_Swich_Group, "FAN 2");
    lv_obj_align(ui_Switch_Fan_2, LV_ALIGN_TOP_MID, 0, 230);

    // ui_Switch_Fan_3
    ui_Switch_Fan_3 = create_switch(ui_Swich_Group, "FAN 3");
    lv_obj_align(ui_Switch_Fan_3, LV_ALIGN_TOP_MID, 0, 330);
}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen_1_Print_screen_init();
    ui_Screen_2_Move_screen_init();
    ui_Screen_3_Setting_screen_init();
    lv_disp_load_scr(ui_Screen_1_Print);
}
