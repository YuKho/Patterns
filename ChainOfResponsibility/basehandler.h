#ifndef BASEHANDLER_H
#define BASEHANDLER_H

#include <memory>
#include <string>

class BaseHandler
{
public:
    virtual ~BaseHandler();
    virtual void handle(const std::string &data) const;

    void setNextHandler(std::unique_ptr<BaseHandler> &&next);
    void addHandler(std::unique_ptr<BaseHandler> &&handler);

private:
    std::unique_ptr<BaseHandler> _nextHandler;
};

class FirstHandle : public BaseHandler
{
public:
    void handle(const std::string &data) const override;
};

class SecondHandle : public BaseHandler
{
public:
    void handle(const std::string &data) const override;
};

class ThirdHandle : public BaseHandler
{
public:
    void handle(const std::string &data) const override;
};

#endif // BASEHANDLER_H
