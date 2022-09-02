#ifndef _SERIAL_PORT_H_
#define _SERIAL_PORT_H_

#include <Windows.h>

#define MAX_PORT_NUM    20
#define MAX_STR_LEN    20

class SerialPort
{
public:
    SerialPort();
    bool scan(UINT IDList[]);
    HANDLE open(UINT portID);
    bool close(void);
    void write(LPCVOID data_buf, DWORD len);
    DWORD read(LPVOID read_buf);
    void control();
    ~SerialPort();
    UINT com_cnt;
private:
    HANDLE hCom;
    wchar_t ComList[MAX_PORT_NUM][MAX_STR_LEN];
    UINT act_com_id;
    UINT com_id;
};


#endif // _SERIAL_PORT_H_
