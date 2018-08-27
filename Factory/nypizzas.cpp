#include "nypizzas.h"
#include <iostream>

void NYStylePizza::cut() const
{
    std::cout << "Cutting the \'" << getName() << "\' into diagonal slices." << std::endl;
}

NYStyleCheesePizza::NYStyleCheesePizza()
    : NYStylePizza("NY Style Sauce and Cheese Pizza", "Thin Crust Dough", "Marianara Sauce")
{
    addTopping("Grated Reggiano Cheese");
}

NYStylePepperoniPizza::NYStylePepperoniPizza()
    : NYStylePizza("NY Style Pepperoni Pizza", "Thin Crust Dough", "Marinara Sauce")
{
    addTopping("Grated Reggiano Cheese");
    addTopping("Sliced Pepperoni");
    addTopping("Garlic");
    addTopping("Onion");
    addTopping("Mushrooms");
    addTopping("Red Pepper");
}

NYStyleClamPizza::NYStyleClamPizza()
    : NYStylePizza("NY Style Clam Pizza", "Thin Crust Dough", "Marinara Sauce")
{
    addTopping("Grated Reggiano Cheese");
    addTopping("Fresh Clams from Long Island Sound");
}

NYStyleVeggiePizza::NYStyleVeggiePizza()
    : NYStylePizza("NY Style Veggie Pizza", "Thin Crust Dough", "Marinara Sauce")
{
    addTopping("Grated Reggiano Cheese");
    addTopping("Garlic");
    addTopping("Onion");
    addTopping("Mushrooms");
    addTopping("Red Pepper");
}
