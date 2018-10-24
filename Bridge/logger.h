#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <string>

class LoggerImpl;

class Logger
{
public:
    enum class Mode { ST, MT };

public:
    Logger(std::unique_ptr<LoggerImpl> &&impl);

    virtual ~Logger();
    virtual void log(const std::string &str) = 0;

protected:
    static std::unique_ptr<LoggerImpl> createImpl(Logger::Mode mode);

protected:
    std::unique_ptr<LoggerImpl> _pimpl;
};

class ConsoleLogger : public Logger
{
public:
    ConsoleLogger(Logger::Mode mode);
    void log(const std::string &str) override;
};

class FileLogger : public Logger
{
public:
    FileLogger(Logger::Mode mode, std::string file_name);
    void log(const std::string &str) override;

private:
    std::string _file;
};

class SocketLogger : public Logger
{
public:
    SocketLogger(Logger::Mode mode, std::string remote_host, int remote_port);
    void log(const std::string &str) override;

private:
    std::string _host;
    int         _port;
};

#endif // LOGGER_H
