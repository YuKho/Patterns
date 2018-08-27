#include "simplepizza.h"
#include <iostream>

void SimplePizzaPizza::cut() const
{
    std::cout << "Cut the \'" << getName() << "\' into diagonal slices" << std::endl;
}

CheesePizza::CheesePizza() : SimplePizzaPizza("Cheese Pizza", "Regular Crust", "Marinara Pizza Sauce")
{
    addTopping("Fresh Mozzarella");
    addTopping("Parmesan");
}

PepperoniPizza::PepperoniPizza() : SimplePizzaPizza("Pepperoni Pizza", "Crust", "Marinara Sauce")
{
    addTopping("Sliced Pepperoni");
    addTopping("Sliced Onion");
    addTopping("Grated parmesan cheese");
}

ClamPizza::ClamPizza() : SimplePizzaPizza("Clam Pizza", "Thin Crust", "White Garlic Sauce")
{
    addTopping("Clams");
    addTopping("Grated parmesan cheese");
}

VeggiePizza::VeggiePizza() : SimplePizzaPizza("Veggie Pizza", "Crust", "Marinara Sauce")
{
    addTopping("Shredded mozzarella");
    addTopping("Grated parmesan");
    addTopping("Diced onion");
    addTopping("Sliced mushrooms");
    addTopping("Sliced red pepper");
    addTopping("Sliced black olives");
}

void VeggiePizza::cut() const
{
    std::cout << "Cut the \'" << getName() << "\' into triangle form" << std::endl;
}
