#pragma once

#include <condition_variable>
#include <mutex>
#include <sys/ioctl.h>

#define REST_SERV_IP "192.168.1.10"
#define REST_SERV_PORT "8080"

using namespace std;

int printHelloWorld();
void printHorizontalLine();
struct winsize getConsoleSize();

namespace MyLibrary
{
    class InterruptHandler
    {
    private:
        static condition_variable _condition;
        static mutex _mutex;

    public:
        static void hookSIGINT();
        static void handleUserInterrupt(int signal);
        static void waitForUserInterrupt();
    };

    enum RESULT_CODE {
        RESULT_SUCCESS = 0x0000,
        RESULT_UNKNOWN = 0x0001,
        REST_SERV_INIT_ERR = 0x0010,
        SERV_RELEASE_MEM = 0x001F,
    };
} // namespace MyLibrary
