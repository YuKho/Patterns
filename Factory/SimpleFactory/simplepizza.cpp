#include "simplepizza.h"
#include <iostream>
#include <utility>

void SimplePizza::cut() const
{
    std::cout << "Cut the \'" << _name << "\' into diagonal slices" << std::endl;
}

void SimplePizza::prepare() const
{

}

void SimplePizza::bake() const
{

}

void SimplePizza::box() const
{

}

std::ostream &SimplePizza::print(std::ostream &os) const
{
    os << "---- " << _name << " ----\n"
       << _dough << "\n"
       << _sauce << "\n";

    for (const auto &top : _toppings)
        os << top << "\n";

    return os;
}

SimplePizza::SimplePizza(std::string name, std::string dough, std::string sauce)
    : _name(std::move(name)), _dough(std::move(dough)), _sauce(std::move(sauce))
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
    std::cout << "Cut the \'" << _name << "\' into triangle form" << std::endl;
}

std::ostream &operator <<(std::ostream &os, SimplePizza *pizza)
{
    return pizza->print(os);
}
