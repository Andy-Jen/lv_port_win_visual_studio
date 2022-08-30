#include <Windows.h>
#include <tchar.h>
#include "serial_port.h"


SerialPort::SerialPort()
{
    
}

SerialPort::~SerialPort()
{

}

bool SerialPort::scan(UINT IDList[])
{
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
                DWORD i = 0;
                DWORD dwType;
                DWORD dwValueNameSize;
                DWORD dwDataSize;
                LONG nEnum;

                dwValueNameSize = dwMaxValueNameSizeInChars;
                dwDataSize = dwMaxValueDataSizeInBytes;

                nEnum = RegEnumValue(hSERIALCOMM, i,
                    (LPWSTR)pValueName, &dwValueNameSize, NULL, &dwType,
                    (LPBYTE)pValueData, &dwDataSize);

                this->com_cnt = 0;
                while (ERROR_SUCCESS == nEnum)
                {
                    //If the value is of the correct type, then add it to the array
                    if (REG_SZ == dwType)
                    {
                        _stprintf(this->ComList[this->com_cnt], TEXT("%s"), pValueData);
                        _stscanf(this->ComList[this->com_cnt], TEXT("COM%d"), &IDList[this->com_cnt]);
                        this->com_cnt++;
                    }
                    //Prepare for the next time around
                    dwValueNameSize = dwMaxValueNameSizeInChars;
                    dwDataSize = dwMaxValueDataSizeInBytes;
                    ZeroMemory(pValueName, dwMaxValueNameSizeInBytes);
                    ZeroMemory(pValueData, dwMaxValueDataSizeInBytes);
                    i++;
                    nEnum = RegEnumValue(hSERIALCOMM, i, (LPWSTR)pValueName,
                        &dwValueNameSize, NULL, &dwType, (LPBYTE)pValueData, &dwDataSize);
                }
            }
            else
            {
                return FALSE;
            }

            HeapFree(GetProcessHeap(), 0, pValueName);
            HeapFree(GetProcessHeap(), 0, pValueData);
        }
        RegCloseKey(hSERIALCOMM);

        if (dwQueryInfo != ERROR_SUCCESS)
            return FALSE;
    }
    return TRUE;
}


bool SerialPort::open(UINT portID)
{
    DWORD erM = 0;
    wchar_t comName[10];

    if (portID > 9)
    {
        _stprintf(comName, L"\\\\.\\COM%d", portID);
    }
    else
    {
        _stprintf(comName, L"COM%d", portID);
    }
    _tprintf(TEXT("Try open [%s]\n"), comName);
    this->hCom = CreateFile(comName,
        GENERIC_READ | GENERIC_WRITE, //允许读和写
        0,  //独占方式
        NULL,
        OPEN_EXISTING,  //打开而不是创建
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, //重叠方式
        NULL);

    if (this->hCom == INVALID_HANDLE_VALUE)
    {
        _tprintf(TEXT("Open Faild, Close com port\n"));
        CloseHandle(this->hCom);
        this->hCom = NULL;
        return this->hCom;
    }
    _tprintf(TEXT("Open Success\n"));
    return hCom;
}

bool SerialPort::close(void)
{
    _tprintf(TEXT("Close com port success\n"));
    CloseHandle(this->hCom);
    return true;
}
void SerialPort::write(LPCVOID data_buf, DWORD len)
{
    DWORD written;
    if (!WriteFile(this->hCom, data_buf, len, &written, NULL))
    {
        _tprintf(TEXT("Write error %d\n"), written);
    }
}

void SerialPort::read(LPVOID read_buf, DWORD len)
{
    DWORD read_byte;
    ReadFile(this->hCom, read_buf, len, &read_byte, NULL);
    _tprintf(TEXT("Read %d bytes\n"), read_byte);
}


void SerialPort::control()
{
    SetupComm(this->hCom, 1024, 1024); //输入缓冲区和输出缓冲区的大小都是1024
    COMMTIMEOUTS TimeOuts;
    //设定读超时
    TimeOuts.ReadIntervalTimeout = 1000;
    TimeOuts.ReadTotalTimeoutMultiplier = 500;
    TimeOuts.ReadTotalTimeoutConstant = 5000;

    //设定写超时
    TimeOuts.WriteTotalTimeoutMultiplier = 500;
    TimeOuts.WriteTotalTimeoutConstant = 2000;
    SetCommTimeouts(this->hCom, &TimeOuts); //设置超时

    DCB dcb;
    GetCommState(this->hCom, &dcb);
    dcb.BaudRate = 9600; //波特率为9600
    dcb.ByteSize = 8; //每个字节有8位
    dcb.Parity = NOPARITY; //无奇偶校验位
    dcb.StopBits = ONESTOPBIT; //两个停止位
    //SetCommState(this->hCom, &dcb);
    PurgeComm(this->hCom, PURGE_TXCLEAR | PURGE_RXCLEAR);
}
