#include <thread>
#include <iostream>
#include <future>
#include <ctime> 
#include "lvgl/lvgl.h"

extern int gui_thread_main();

using namespace std;

void mySleep(int s)
{
    std::this_thread::sleep_for(std::chrono::duration<double>(s));
}

int main()
{
    thread gui_thread(gui_thread_main);

    while (1)
    {
        mySleep(1000);
    }
}
