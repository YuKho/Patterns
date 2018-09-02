#include "abstractpizza.h"
#include <utility>
#include <iostream>

AbstractPizza::AbstractPizza(std::string name) : _name(std::move(name))
{
}

std::string AbstractPizza::name() const
{
    return _name;
}

void AbstractPizza::bake() const
{
    std::cout << "Bake for 25 minutes at 350." << std::endl;
}

void AbstractPizza::box() const
{
    std::cout << "Place \'" << _name << "\' in official PizzaStore box." << std::endl;
}

void AbstractPizza::cut() const
{
    std::cout << "Cutting the \'" << _name << "\' into diagonal slices" << std::endl;
}

std::ostream &operator <<(std::ostream &os, const AbstractPizza &pizza)
{
    return pizza.print(os);
}

std::ostream &operator <<(std::ostream &os, AbstractPizza *pizza)
{
    return pizza->print(os);
}
