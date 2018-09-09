#include "adapters.h"
#include "turkeys.h"
#include <utility>

TurkeyAdapter::TurkeyAdapter(std::shared_ptr<Turkey> source) : _adaptee(std::move(source))
{
}

void TurkeyAdapter::quack() const
{
    _adaptee->gobble();
}

void TurkeyAdapter::fly() const
{
    for (int i = 0; i < 5; ++i)
        _adaptee->fly();
}
