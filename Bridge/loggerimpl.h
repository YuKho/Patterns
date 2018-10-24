#ifndef LOGGERIMPL_H
#define LOGGERIMPL_H

#include <string>

class LoggerImpl
{
public:
    LoggerImpl() {}
    virtual ~LoggerImpl() {}
    virtual void console_log(const std::string &str) = 0;
    virtual void file_log(const std::string &file, const std::string &str) = 0;
    virtual void socket_log(const std::string &host, int port, const std::string &str) = 0;
};

class ST_LoggerImpl : public LoggerImpl
{
public:
    void console_log(const std::string &str) override;
    void file_log(const std::string &file, const std::string &str) override;
    void socket_log(const std::string &host, int port, const std::string &str) override;
};

class MT_LoggerImpl : public LoggerImpl
{
public:
    void console_log(const std::string &str) override;
    void file_log(const std::string &file, const std::string &str) override;
    void socket_log(const std::string &host, int port, const std::string &str) override;
};

#endif // LOGGERIMPL_H
