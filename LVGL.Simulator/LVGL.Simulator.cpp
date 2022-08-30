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
#define MAX_PORT_NUM    20
#define MAX_STR_LEN    20
UINT win_com_scan(wchar_t pPortName[][MAX_STR_LEN])
{
    UINT com_cnt = 0;

    HKEY hSERIALCOMM;

    if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE,
        TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM"), 0, KEY_QUERY_VALUE, &hSERIALCOMM)
        )
    {
        //Get the max value name and max value lengths
        DWORD dwMaxValueNameLen;
        DWORD dwMaxValueLen;
        DWORD dwQueryInfo;

        dwQueryInfo = RegQueryInfoKey(hSERIALCOMM, NULL, NULL,
            NULL, NULL, NULL, NULL, NULL,
            &dwMaxValueNameLen, &dwMaxValueLen, NULL, NULL);

        if (ERROR_SUCCESS == dwQueryInfo)
        {
            DWORD dwMaxValueNameSizeInChars, dwMaxValueNameSizeInBytes,
                dwMaxValueDataSizeInChars, dwMaxValueDataSizeInBytes;

            DWORD* pValueName;
            DWORD* pValueData;

            dwMaxValueNameSizeInChars = dwMaxValueNameLen + 1; //Include space for the NULL terminator
            dwMaxValueNameSizeInBytes = dwMaxValueNameSizeInChars * sizeof(TCHAR);
            dwMaxValueDataSizeInChars = dwMaxValueLen / sizeof(TCHAR) + 1; //Include space for the NULL terminator
            dwMaxValueDataSizeInBytes = dwMaxValueDataSizeInChars * sizeof(TCHAR);

            //Allocate some space for the value name and value data      

            pValueName = (DWORD*)(GUID*)HeapAlloc(GetProcessHeap(),
                HEAP_GENERATE_EXCEPTIONS | HEAP_ZERO_MEMORY, dwMaxValueNameSizeInBytes);
            pValueData = (DWORD*)(GUID*)HeapAlloc(GetProcessHeap(),
                HEAP_GENERATE_EXCEPTIONS | HEAP_ZERO_MEMORY, dwMaxValueDataSizeInBytes);

            if (NULL != pValueName && NULL != pValueData)
            {
                //Enumerate all the values underneath HKEY_LOCAL_MACHINE\HARDWARE\DEVICEMAP\SERIALCOMM
                DWORD i;
                DWORD dwType;
                DWORD dwValueNameSize;
                DWORD dwDataSize;
                LONG nEnum;


                dwValueNameSize = dwMaxValueNameSizeInChars;
                dwDataSize = dwMaxValueDataSizeInBytes;

                i = 0;

                nEnum = RegEnumValue(hSERIALCOMM, i,
                    (LPWSTR)pValueName, &dwValueNameSize, NULL, &dwType,
                    (LPBYTE)pValueData, &dwDataSize);

                com_cnt = 0;
                while (ERROR_SUCCESS == nEnum)
                {
                    //If the value is of the correct type, then add it to the array
                    if (REG_SZ == dwType)
                    {
                        _stprintf(pPortName[com_cnt], TEXT("%s"), pValueData);
                        com_cnt++;
                    }/*if */

                    //Prepare for the next time around
                    dwValueNameSize = dwMaxValueNameSizeInChars;
                    dwDataSize = dwMaxValueDataSizeInBytes;
                    ZeroMemory(pValueName, dwMaxValueNameSizeInBytes);
                    ZeroMemory(pValueData, dwMaxValueDataSizeInBytes);
                    i++;
                    nEnum = RegEnumValue(hSERIALCOMM, i, (LPWSTR)pValueName,
                        &dwValueNameSize, NULL, &dwType, (LPBYTE)pValueData, &dwDataSize);
                    
                }/*while*/
            }
            else
            {
                return FALSE;
            }/*if NULL != pValueName && NULL != pValueData*/

            HeapFree(GetProcessHeap(), 0, pValueName);
            HeapFree(GetProcessHeap(), 0, pValueData);
        }/*ERROR_SUCCESS == dwQueryInfo*/

        //Close the registry key now that we are finished with it    
        RegCloseKey(hSERIALCOMM);

        if (dwQueryInfo != ERROR_SUCCESS)
            return FALSE;
    }/*ERROR_SUCCESS == RegOpenKeyEx*/

    return com_cnt;
}/*EnumerateComPortRegistry*/


HANDLE win_com_open(LPCWSTR protname)
{
    HANDLE hCom;  //全局变量，串口句柄
    DWORD erM = 0;
    int portID = 0;
    wchar_t comName[10];
    _stscanf(protname, TEXT("COM%d"), &portID);
    if (portID > 9)
    {
        _stprintf(comName, L"\\\\.\\%s", protname);
    }
    else
    {
        _stprintf(comName, L"%s", protname);
    }
    _tprintf(TEXT("Try open [%s]\n"), comName);
    hCom = CreateFile(comName,
        GENERIC_READ | GENERIC_WRITE, //允许读和写
        0,  //独占方式
        NULL,
        OPEN_EXISTING,  //打开而不是创建
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, //重叠方式
        NULL);

    if (hCom == INVALID_HANDLE_VALUE)
    {
        _tprintf(TEXT("Open Faild, Close com port"));
        CloseHandle(hCom);
        hCom = NULL;
        return hCom;
    }
    _tprintf(TEXT("Open Success"));
    return hCom;
}


bool win_com_close(HANDLE hCom)
{
    _tprintf(TEXT("Close com port success"));
    CloseHandle(hCom);
    return true;
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
    ui_init();
    
    lv_obj_add_flag(ui_IMG_USB, LV_OBJ_FLAG_HIDDEN);

    wchar_t portName[MAX_PORT_NUM][MAX_STR_LEN];
    UINT n;
    HANDLE hCom;

    _tprintf(TEXT("\nQueryDosDevice method : \n"));
    n = win_com_scan(portName);
    for (UINT i = 0; i < n; i++)
        _tprintf(TEXT("\t%s\n"), portName[i]);

    hCom = win_com_open(portName[1]);
    if (hCom != NULL)
    {
        win_com_close(hCom);
    }
    while (!lv_win32_quit_signal)
    {
        lv_task_handler();
        Sleep(1);
    }

    return 0;
}
