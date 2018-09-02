#include "simplepizza.h"
#include <iostream>
#include <utility>

void SimplePizza::prepare() const
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

std::ostream &SimplePizza::print(std::ostream &os) const
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

SimplePizza::SimplePizza(std::string name, std::string dough, std::string sauce)
    : AbstractPizza(std::move(name)), _dough(std::move(dough)), _sauce(std::move(sauce))
{
}

void SimplePizza::addTopping(std::string top)
{
    _toppings.push_back(std::move(top));
}

SimpleCheesePizza::SimpleCheesePizza() : SimplePizza("Cheese Pizza", "Regular Crust", "Marinara Pizza Sauce")
{
    addTopping("Fresh Mozzarella");
    addTopping("Parmesan");
}

SimplePepperoniPizza::SimplePepperoniPizza() : SimplePizza("Pepperoni Pizza", "Crust", "Marinara Sauce")
{
    addTopping("Sliced Pepperoni");
    addTopping("Sliced Onion");
    addTopping("Grated parmesan cheese");
}

SimpleClamPizza::SimpleClamPizza() : SimplePizza("Clam Pizza", "Thin Crust", "White Garlic Sauce")
{
    addTopping("Clams");
    addTopping("Grated parmesan cheese");
}

SimpleVeggiePizza::SimpleVeggiePizza() : SimplePizza("Veggie Pizza", "Crust", "Marinara Sauce")
{
    addTopping("Shredded mozzarella");
    addTopping("Grated parmesan");
    addTopping("Diced onion");
    addTopping("Sliced mushrooms");
    addTopping("Sliced red pepper");
    addTopping("Sliced black olives");
}

void SimpleVeggiePizza::cut() const
{
    std::cout << "Cut the \'" << name() << "\' into triangle form" << std::endl;
}
