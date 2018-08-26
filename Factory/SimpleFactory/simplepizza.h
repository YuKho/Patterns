#ifndef SIMPLEPIZZA_H
#define SIMPLEPIZZA_H

#include "../pizza.h"

class CheesePizza : public Pizza
{
public:
    CheesePizza() : Pizza("Cheese Pizza", "Regular Crust", "Marinara Pizza Sauce")
    {
        addTopping("Fresh Mozzarella");
        addTopping("Parmesan");
    }
};

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza() : Pizza("Pepperoni Pizza", "Crust", "Marinara Sauce")
    {
        addTopping("Sliced Pepperoni");
        addTopping("Sliced Onion");
        addTopping("Grated parmesan cheese");
    }
};

class ClamPizza : public Pizza
{
public:
    ClamPizza() : Pizza("Clam Pizza", "Thin Crust", "White Garlic Sauce")
    {
        addTopping("Clams");
        addTopping("Grated parmesan cheese");
    }
};

class VeggiePizza : public Pizza
{
public:
    VeggiePizza() : Pizza("Veggie Pizza", "Crust", "Marinara Sauce")
    {
        addTopping("Shredded mozzarella");
        addTopping("Grated parmesan");
        addTopping("Diced onion");
        addTopping("Sliced mushrooms");
        addTopping("Sliced red pepper");
        addTopping("Sliced black olives");
    }
};

#endif // SIMPLEPIZZA_H
