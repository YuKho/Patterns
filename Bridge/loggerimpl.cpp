#include "loggerimpl.h"
#include <iostream>

using namespace std;

void ST_LoggerImpl::console_log(const std::string &str)
{
    cout << "Single-threaded console logger" << endl;
}

void ST_LoggerImpl::file_log(const std::string &file, const std::string &str)
{
    cout << "Single-threaded file logger" << endl;
}

void ST_LoggerImpl::socket_log(const std::string &host, int port, const std::string &str)
{
    cout << "Single-threaded socket logger" << endl;
}

void MT_LoggerImpl::console_log(const std::string &str)
{
    cout << "Multithreaded console logger" << endl;
}

void MT_LoggerImpl::file_log(const std::string &file, const std::string &str)
{
    cout << "Multithreaded file logger" << endl;
}

void MT_LoggerImpl::socket_log(const std::string &host, int port, const std::string &str)
{
    cout << "Multithreaded socket logger" << endl;
}
