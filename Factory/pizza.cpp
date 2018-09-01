#include "pizza.h"
#include "ingredients.h"
#include "pizzaingredientfactory.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>

Pizza::Pizza(std::string name, std::weak_ptr<PizzaIngredientFactory> factory)
    : _ingredientFactory(std::move(factory)), _name(std::move(name))
{
}

void Pizza::createVeggies()
{
    auto veggies = _ingredientFactory.lock()->createVeggies();
    std::move(std::begin(veggies), std::end(veggies),
              std::back_inserter(_veggies));
}

void Pizza::cut() const
{
    std::cout << "Cutting the \'" << _name << "\' into diagonal slices" << std::endl;
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
    os << "---- " << _name << " ----\n";
    if (_dough)     os << _dough->name() << "\n";
    if (_sauce)     os << _sauce->name() << "\n";
    if (_cheese)    os << _cheese->name() << "\n";
    if (_clam)      os << _clam->name() << "\n";
    if (_pepperoni) os << _pepperoni->name() << "\n";

    for (const auto &veggie : _veggies)
        if (veggie) os << veggie.get() << "\n";

    return os;
}

std::ostream &operator <<(std::ostream &os, Pizza *pizza)
{
    return pizza->print(os);
}
