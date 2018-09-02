#include "pizza.h"
#include "pizzaingredientfactory.h"
#include <iostream>
#include <utility>

Pizza::Pizza(std::string name, std::weak_ptr<PizzaIngredientFactory> factory)
    : AbstractPizza(std::move(name)), _ingredientFactory(std::move(factory))
{
}

void Pizza::prepare()
{
    if (_ingredientFactory.expired())
        return;

    std::cout << "Preparing " << name();
    prepareImpl();
}

std::ostream &Pizza::print(std::ostream &os) const
{
    os << "---- " << name() << " ----\n";
    if (_dough)     os << _dough->name() << "\n";
    if (_sauce)     os << _sauce->name() << "\n";
    if (_cheese)    os << _cheese->name() << "\n";
    if (_clam)      os << _clam->name() << "\n";
    if (_pepperoni) os << _pepperoni->name() << "\n";

    if (!_veggies.empty())
        os << "Veggies:\n";
    for (const auto &veggie : _veggies)
        if (veggie) os << "\t" << veggie->name() << "\n";

    return os;
}
