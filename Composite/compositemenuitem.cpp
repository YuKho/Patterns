#include "compositemenuitem.h"
#include <utility>
#include <iostream>

CompositeMenuItem::CompositeMenuItem(std::string name, std::string description, bool vegetarian,
                                     double price)
    : _name(std::move(name)), _description(std::move(description)), _vegetarian(vegetarian),
      _price(price)
{
}

void CompositeMenuItem::add(std::shared_ptr<MenuComponent>)
{
    std::cerr << "UNSUPPORTED OPERATION" << std::endl;
}

void CompositeMenuItem::remove(const std::shared_ptr<MenuComponent> &)
{
    std::cerr << "UNSUPPORTED OPERATION" << std::endl;
}

std::shared_ptr<MenuComponent> CompositeMenuItem::getChild(size_t)
{
    std::cerr << "UNSUPPORTED OPERATION" << std::endl;
    return nullptr;
}

std::string CompositeMenuItem::getName() const
{
    return _name;
}

std::string CompositeMenuItem::getDescription() const
{
    return _description;
}

double CompositeMenuItem::getPrice() const
{
    return _price;
}

bool CompositeMenuItem::isVegetarian() const
{
    return _vegetarian;
}

void CompositeMenuItem::print() const
{
    std::cout << "  " + getName();
    if (isVegetarian())
        std::cout << " (v)" << std::endl;

    std::cout << ", " << getPrice() << "     -- " << getDescription() << std::endl;
}
