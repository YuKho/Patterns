#include "adapters.h"
#include <utility>

TurkeyObjectAdapter::TurkeyObjectAdapter(std::shared_ptr<Turkey> source) : _adaptee(std::move(source))
{
}

void TurkeyObjectAdapter::quack() const
{
    _adaptee->gobble();
}

void TurkeyObjectAdapter::fly() const
{
    for (int i = 0; i < 5; ++i)
        _adaptee->fly();
}

void TurkeyClassAdapter::quack() const
{
    WildTurkey::gobble();
}

void TurkeyClassAdapter::fly() const
{
    for (int i = 0; i < 5; ++i)
        WildTurkey::fly();
}
