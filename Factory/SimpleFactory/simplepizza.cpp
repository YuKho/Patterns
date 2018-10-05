#include "simplepizza.h"
#include <iostream>
#include <utility>

void SimpleFactory::Pizza::prepare()
{
    std::cout << "Preparing " << name() << "\n";
    std::cout << "Tossing dough...,\t";
    std::cout << "Adding sauce...";

    if (!_toppings.empty())
    {
        std::cout << "Adding toppings: \n";
        for (const auto &topping : _toppings)
            std::cout << "\t" << topping;
    }
}

std::ostream &SimpleFactory::Pizza::print(std::ostream &os) const
{
    os << "---- " << name() << " ----\n"
       << _dough << "\n"
       << _sauce << "\n";

    if (!_toppings.empty())
    {
        os << "Toppings:\n";
        for (const auto &topping : _toppings)
            os << "\t" << topping << "\n";
    }

    return os;
}

SimpleFactory::Pizza::Pizza(std::string name, std::string dough, std::string sauce)
    : AbstractPizza(std::move(name)), _dough(std::move(dough)), _sauce(std::move(sauce))
{
}

void SimpleFactory::Pizza::addTopping(std::string top)
{
    _toppings.push_back(std::move(top));
}

SimpleFactory::CheesePizza::CheesePizza() : Pizza("Cheese Pizza", "Regular Crust", "Marinara Pizza Sauce")
{
    addTopping("Fresh Mozzarella");
    addTopping("Parmesan");
}

SimpleFactory::PepperoniPizza::PepperoniPizza() : Pizza("Pepperoni Pizza", "Crust", "Marinara Sauce")
{
    addTopping("Sliced Pepperoni");
    addTopping("Sliced Onion");
    addTopping("Grated parmesan cheese");
}

SimpleFactory::ClamPizza::ClamPizza() : Pizza("Clam Pizza", "Thin Crust", "White Garlic Sauce")
{
    addTopping("Clams");
    addTopping("Grated parmesan cheese");
}

SimpleFactory::VeggiePizza::VeggiePizza() : Pizza("Veggie Pizza", "Crust", "Marinara Sauce")
{
    addTopping("Shredded mozzarella");
    addTopping("Grated parmesan");
    addTopping("Diced onion");
    addTopping("Sliced mushrooms");
    addTopping("Sliced red pepper");
    addTopping("Sliced black olives");
}

void SimpleFactory::VeggiePizza::cut() const
{
    std::cout << "Cut the \'" << name() << "\' into triangle form" << std::endl;
}
