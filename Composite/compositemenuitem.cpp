#include "compositemenuitem.h"
#include <utility>
#include <iostream>

Composite::MenuItem::MenuItem(std::string name, std::string description, bool vegetarian,
                                     double price)
    : MenuComponent(std::move(name), std::move(description)),
      _vegetarian(vegetarian),
      _price(price)
{
}

double Composite::MenuItem::getPrice() const
{
    return _price;
}

bool Composite::MenuItem::isVegetarian() const
{
    return _vegetarian;
}

void Composite::MenuItem::print() const
{
    std::cout << "  " + getName();
    if (isVegetarian())
        std::cout << " (v)";

    std::cout << ", " << getPrice() << "     -- " << getDescription() << std::endl;
}

Composite::MenuItem *Composite::MenuItem::getMenuItem()
{
    return this;
}

const Composite::MenuItem *Composite::MenuItem::getMenuItem() const
{
    return this;
}
