#include "logger.h"
#include "loggerimpl.h"
#include <utility>

Logger::Logger(std::unique_ptr<LoggerImpl> &&impl) : _pimpl(std::move(impl))
{
}

Logger::~Logger() = default;

std::unique_ptr<LoggerImpl> Logger::createImpl(Logger::Mode mode)
{
    switch (mode)
    {
    case Mode::ST:
        return std::make_unique<ST_LoggerImpl>();

    case Mode::MT:
        return std::make_unique<MT_LoggerImpl>();
    }

    return nullptr;
}

ConsoleLogger::ConsoleLogger(Logger::Mode mode)
    : Logger(createImpl(mode))
{
}

void ConsoleLogger::log(const std::string &str)
{
    _pimpl->console_log(str);
}

FileLogger::FileLogger(Logger::Mode mode, std::string file_name)
    : Logger(createImpl(mode)), _file(std::move(file_name))
{
}

void FileLogger::log(const std::string &str)
{
    _pimpl->file_log(_file, str);
}

SocketLogger::SocketLogger(Logger::Mode mode, std::string remote_host, int remote_port)
    : Logger(createImpl(mode)), _host(std::move(remote_host)), _port(remote_port)
{
}

void SocketLogger::log(const std::string &str)
{
    _pimpl->socket_log(_host, _port, str);
}
