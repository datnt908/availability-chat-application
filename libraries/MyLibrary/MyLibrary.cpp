#include "MyLibrary.h"

#include <iostream>
#include <signal.h>
#include <unistd.h>

int printHelloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

void printHorizontalLine()
{
    unsigned short width = getConsoleSize().ws_col;
    for (unsigned short i = 0; i < width; ++i)
        cout << '=';
    cout << '\n';
}

struct winsize getConsoleSize()
{
    struct winsize _winsize;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &_winsize);
    return _winsize;
}

namespace MyLibrary
{
    condition_variable InterruptHandler::_condition;
    mutex InterruptHandler::_mutex;

    void InterruptHandler::hookSIGINT()
    {
        signal(SIGINT, handleUserInterrupt);
    }
    void InterruptHandler::handleUserInterrupt(int signal)
    {
        if (signal == SIGINT)
        {
            _condition.notify_one();
        }
    }
    void InterruptHandler::waitForUserInterrupt()
    {
        std::unique_lock<std::mutex> lock{_mutex};
        _condition.wait(lock);
        lock.unlock();
    }
} // namespace MyLibrary