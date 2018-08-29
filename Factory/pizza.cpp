#include "pizza.h"
#include <iostream>
#include <utility>

Pizza::Pizza(std::string name, std::string dough, std::string sauce)
    : _name(std::move(name)), _dough(std::move(dough)), _sauce(std::move(sauce))
{
}

Pizza::Pizza(std::weak_ptr<PizzaIngredientFactory> factory)
    : _ingredientFactory(std::move(factory))
{
}

void Pizza::bake() const
{
    std::cout << "Bake for 25 minutes at 350." << std::endl;
}

void Pizza::box() const
{
    std::cout << "Place \'" << _name << "\' in official PizzaStore box." << std::endl;
}

std::string Pizza::getName() const
{
    return _name;
}

void Pizza::setName(std::string name)
{
    _name = std::move(name);
}

std::ostream &Pizza::print(std::ostream &os) const
{
    os << "---- " << _name << " ----\n"
       << _dough << "\n"
       << _sauce << "\n";

    for (const auto &top : _toppings)
        os << top << "\n";

    return os;
}

void Pizza::addTopping(std::string top)
{
    _toppings.push_back(std::move(top));
}

std::ostream &operator <<(std::ostream &os, Pizza *pizza)
{
    return pizza->print(os);
}
