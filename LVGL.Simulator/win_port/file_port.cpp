#include <Windows.h>
#include <tchar.h>
#include "file_port.h"


FilePort::FilePort()
{
    
}

FilePort::~FilePort()
{

}

bool FilePort::scan(UINT IDList[])
{
    return 0;
}

bool FilePort::open(LPCWSTR FileName)
{
    this->hFile = CreateFile(FileName,     //创建文件的名称。
        GENERIC_WRITE | GENERIC_READ,          // 写和读文件。
        0,                      // 不共享读写。
        NULL,                   // 缺省安全属性。
        CREATE_ALWAYS,          // 如果文件存在，也创建。
        FILE_ATTRIBUTE_NORMAL, // 一般的文件。       
        NULL);                 // 模板文件为空。
    if (this->hFile == INVALID_HANDLE_VALUE)
    {
        _tprintf(TEXT("CreateFile fail!\r\n"));
    }
    return 0;
}

bool FilePort::close(void)
{
    _tprintf(TEXT("Close com port success\n"));
    CloseHandle(this->hFile);
    return true;
}

void FilePort::write(LPCVOID data_buf, DWORD len)
{
    DWORD written = 0;
    if (WriteFile(this->hFile, data_buf, len, &written, NULL))
    {
        _tprintf(TEXT("WriteFile success\r\n"));
    }
    else
    {
        _tprintf(TEXT("WriteFile failed [%d]\r\n"), written);
    }
}

void FilePort::read(LPVOID read_buf, DWORD len)
{
    DWORD dwReadSize = 0;
    if (ReadFile(this->hFile, read_buf, len, &dwReadSize, NULL))
    {
        _tprintf(TEXT("ReadFile success\r\n"));
    }
    else
    {
        //获取出错码。
        DWORD dwError = GetLastError();
        //处理出错。            
        TCHAR chErrorBuf[1024];
        wsprintf(chErrorBuf, TEXT("GetLastError()=%d\r\n"), dwError);
        _tprintf(chErrorBuf);
    }
}

void FilePort::control()
{

}
