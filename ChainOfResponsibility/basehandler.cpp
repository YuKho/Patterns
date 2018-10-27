#include "basehandler.h"
#include <utility>
#include <iostream>

BaseHandler::~BaseHandler() = default;

void BaseHandler::handle(const std::string &data) const
{
    if (_nextHandler)
        _nextHandler->handle(data);
    else
        std::cout << "Default handler had been handled the data." << std::endl;
}

void BaseHandler::setNextHandler(std::unique_ptr<BaseHandler> &&next)
{
    _nextHandler = std::move(next);
}

void BaseHandler::addHandler(std::unique_ptr<BaseHandler> &&handler)
{
    if (_nextHandler)
        _nextHandler->addHandler(std::move(handler));
    else
        setNextHandler(std::move(handler));
}

void FirstHandle::handle(const std::string &data) const
{
    if (data == "first")
    {
        std::cout << "First handler had been handled the data." << std::endl;
        return;
    }

    std::cout << "First handler passed the data to next handler..." << std::endl;
    BaseHandler::handle(data);
}

void SecondHandle::handle(const std::string &data) const
{
    if (data == "second")
    {
        std::cout << "Second handler had been handled the data." << std::endl;
        return;
    }

    std::cout << "Second handler passed the data to next handler..." << std::endl;
    BaseHandler::handle(data);
}

void ThirdHandle::handle(const std::string &data) const
{
    if (data == "third")
    {
        std::cout << "Third handler had been handled the data." << std::endl;
        return;
    }

    std::cout << "Third handler passed the data to next handler..." << std::endl;
    BaseHandler::handle(data);
}
