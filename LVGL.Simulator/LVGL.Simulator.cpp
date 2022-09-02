/*
 * PROJECT:   LVGL PC Simulator using Visual Studio
 * FILE:      LVGL.Simulator.cpp
 * PURPOSE:   Implementation for LVGL ported to Windows Desktop
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
 */

#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <setupapi.h>
#include <locale.h>
#include <string>
#include <iostream>
#include "resource.h"
#include "serial_port.h"
#include "file_port.h"

using namespace std;

#if _MSC_VER >= 1200
 // Disable compilation warnings.
#pragma warning(push)
// nonstandard extension used : bit field types other than int
#pragma warning(disable:4214)
// 'conversion' conversion from 'type1' to 'type2', possible loss of data
#pragma warning(disable:4244)
#endif

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/win32drv/win32drv.h"
#include "ui_demo/ui.h"

#if _MSC_VER >= 1200
// Restore compilation warnings.
#pragma warning(pop)
#endif

#include <stdio.h>

SerialPort serial;

#define CANVAS_WIDTH  200
#define CANVAS_HEIGHT  150

void lv_example_canvass(void)
{
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);
    rect_dsc.radius = 10;
    rect_dsc.bg_opa = LV_OPA_COVER;
    rect_dsc.bg_grad.dir = LV_GRAD_DIR_HOR;
    rect_dsc.bg_grad.stops[0].color = lv_palette_main(LV_PALETTE_RED);
    rect_dsc.bg_grad.stops[1].color = lv_palette_main(LV_PALETTE_BLUE);
    rect_dsc.border_width = 2;
    rect_dsc.border_opa = LV_OPA_90;
    rect_dsc.border_color = lv_color_white();
    rect_dsc.shadow_width = 5;
    rect_dsc.shadow_ofs_x = 5;
    rect_dsc.shadow_ofs_y = 5;

    lv_draw_label_dsc_t label_dsc;
    lv_draw_label_dsc_init(&label_dsc);
    label_dsc.color = lv_palette_main(LV_PALETTE_ORANGE);

    static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];

    lv_obj_t* canvas = lv_canvas_create(lv_scr_act());
    lv_canvas_set_buffer(canvas, cbuf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_center(canvas);
    lv_canvas_fill_bg(canvas, lv_palette_lighten(LV_PALETTE_GREY, 3), LV_OPA_COVER);

    lv_canvas_draw_rect(canvas, 70, 60, 100, 70, &rect_dsc);

    lv_canvas_draw_text(canvas, 40, 20, 100, &label_dsc, "Some text on text canvas");

    /*Test the rotation. It requires another buffer where the original image is stored.
     *So copy the current image to buffer and rotate it to the canvas*/
    static lv_color_t cbuf_tmp[CANVAS_WIDTH * CANVAS_HEIGHT];
    memcpy(cbuf_tmp, cbuf, sizeof(cbuf_tmp));
    lv_img_dsc_t img;
    img.data = (const uint8_t*)cbuf_tmp;
    img.header.cf = LV_IMG_CF_TRUE_COLOR;
    img.header.w = CANVAS_WIDTH;
    img.header.h = CANVAS_HEIGHT;

    lv_canvas_fill_bg(canvas, lv_palette_lighten(LV_PALETTE_GREY, 3), LV_OPA_COVER);
    lv_canvas_transform(canvas, &img, 120, LV_IMG_ZOOM_NONE, 0, 0, CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, true);
}


UINT port_id[20];

void refresh_serial_list(lv_obj_t* list_obj)
{
    if (serial.scan(port_id) != TRUE)
    {
        _tprintf(TEXT("Scan serial port failed."));
    }
    else
    {
        _tprintf(TEXT("Scan serial port success, find com count: %d\n"), serial.com_cnt);
        lv_dropdown_clear_options(list_obj);
        lv_dropdown_set_selected(list_obj, -1);
        char p_buf[20];
        for (UINT i = 0; i < serial.com_cnt; i++)
        {
            sprintf_s(p_buf, "COM %d", port_id[i]);
            lv_dropdown_add_option(list_obj, p_buf, LV_DROPDOWN_POS_LAST);
            memset(p_buf, 0, 20);
        }
    }
}

static void event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* obj = lv_event_get_target(e);
    if (code == LV_EVENT_VALUE_CHANGED) {
        int get_id;
        get_id = lv_dropdown_get_selected(obj);
        LV_LOG_USER("Open serial port: %d", get_id);
        serial.close();
        serial.open(port_id[get_id]);
        serial.control();
    }
    else if (code == LV_EVENT_CLICKED) {
        refresh_serial_list(obj);
    }
}

static void btn_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
        char data_buf[20] = "Hello Serial.";
        serial.write(data_buf, 20);
        //char read_buf[20];
        //serial.read(read_buf, 20);
        //cout << "Read Serial data: " << read_buf << endl;
    }
    else if (code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}



int gui_thread_main()
{
    lv_init();

    if (!lv_win32_init(
        GetModuleHandleW(NULL),
        SW_SHOW,
        800,
        480,
        LoadIconW(GetModuleHandleW(NULL), MAKEINTRESOURCE(IDI_LVGL))))
    {
        return -1;
    }

    lv_win32_add_all_input_devices_to_group(NULL);
    static lv_color_t canvas_buf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];

    lv_obj_t* canvas_obj = lv_canvas_create(lv_scr_act());
    lv_obj_center(canvas_obj);
    lv_memset_ff(canvas_buf, LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT));
    lv_canvas_set_buffer(canvas_obj, canvas_buf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_canvas_fill_bg(canvas_obj, lv_palette_lighten(LV_PALETTE_YELLOW, 3), LV_OPA_COVER);
    lv_obj_set_style_border_color(canvas_obj, lv_color_black(), LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(canvas_obj, 3, LV_STATE_DEFAULT);
    lv_obj_set_style_radius(canvas_obj, 5, LV_STATE_DEFAULT);
    lv_obj_t* label_obj = lv_label_create(lv_scr_act());
    lv_label_set_text(label_obj, "Hello LVGL");
    lv_obj_center(label_obj);

//    ui_init();
    
//    lv_obj_add_flag(ui_IMG_USB, LV_OBJ_FLAG_HIDDEN);
    lv_obj_t* dd = lv_dropdown_create(lv_scr_act());
    lv_obj_align(dd, LV_ALIGN_TOP_MID, 0, 20);
    lv_obj_add_event_cb(dd, event_handler, LV_EVENT_ALL, NULL);
    lv_dropdown_clear_options(dd);

    lv_obj_t* label;

    lv_obj_t* btn2 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn2, btn_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Toggle");
    lv_obj_center(label);

    refresh_serial_list(dd);

    lv_obj_t* label_view = lv_obj_create(lv_scr_act());
    label = lv_label_create(label_view);
    lv_label_set_text(label, "Hitemm\r\n");
    lv_obj_align(label, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_label_ins_text(label, LV_LABEL_POS_LAST, "Emmm");

    FilePort FileTest;
    char data_buf[20] = "Hello win32.";

    FileTest.open(TEXT("D://TestFiles.txt"));
    FileTest.write(data_buf, strlen(data_buf));

    char read_buf[20];
    FileTest.read(read_buf, 10);
    _tprintf(TEXT("Read file: %s\r\n"), read_buf);
    FileTest.close();

    while (!lv_win32_quit_signal)
    {
        lv_task_handler();
        Sleep(1);
    }

    return 0;
}
