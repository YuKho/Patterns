#include "abstractpizza.h"
#include <utility>

std::string AbstractPizza::name() const
{
    return _name;
}

void AbstractPizza::setName(std::string name)
{
    _name = std::move(name);
}

std::ostream &operator <<(std::ostream &os, const AbstractPizza &pizza)
{
    return pizza.print(os);
}
