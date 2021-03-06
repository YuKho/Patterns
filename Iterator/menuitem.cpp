#include "menuitem.h"
#include <utility>

MenuItem::MenuItem(std::string name, std::string description, bool vegetarian, double price)
    : _name(std::move(name)), _description(std::move(description)), _vegetarian(vegetarian),
      _price(price)
{
}

std::string MenuItem::getName() const
{
    return _name;
}

std::string MenuItem::getDescription() const
{
    return _description;
}

double MenuItem::getPrice() const
{
    return _price;
}

bool MenuItem::isVegetarian() const
{
    return _vegetarian;
}

std::string MenuItem::toString() const
{
    return _name + ", $" + std::to_string(_price) + " --- [" + _description + "]";
}
