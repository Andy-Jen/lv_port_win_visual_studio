#ifndef _FILE_PORT_H_
#define _FILE_PORT_H_

#include <Windows.h>

#define MAX_PORT_NUM    20
#define MAX_STR_LEN    20

class FilePort
{
public:
    FilePort();
    bool scan(UINT IDList[]);
    bool open(LPCWSTR FileName);
    bool close(void);
    void write(LPCVOID data_buf, DWORD len);
    void read(LPVOID read_buf, DWORD len);
    void control();
    ~FilePort();
private:
    HANDLE hFile;
    wchar_t FileList[MAX_PORT_NUM][MAX_STR_LEN];
};


#endif // _File_PORT_H_
