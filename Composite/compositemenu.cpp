#include "compositemenu.h"
#include <utility>
#include <iostream>
#include <algorithm>

CompositeMenu::CompositeMenu(std::string name, std::string description)
    : _name(std::move(name)), _description(std::move(description))
{
}

void CompositeMenu::add(std::shared_ptr<MenuComponent> menuComponent)
{
    _menuComponents.push_back(std::move(menuComponent));
}

void CompositeMenu::remove(const std::shared_ptr<MenuComponent> &menuComponent)
{
    auto it = std::find(_menuComponents.cbegin(), _menuComponents.cend(), menuComponent);
    if (it != _menuComponents.cend())
        _menuComponents.erase(it);
}

std::shared_ptr<MenuComponent> CompositeMenu::getChild(size_t index)
{
    return _menuComponents[index];
}

std::string CompositeMenu::getName() const
{
    return _name;
}

std::string CompositeMenu::getDescription() const
{
    return _description;
}

double CompositeMenu::getPrice() const
{
    std::cerr << "UNSUPPORTED OPERATION" << std::endl;
    return 0;
}

bool CompositeMenu::isVegetarian() const
{
    std::cerr << "UNSUPPORTED OPERATION" << std::endl;
    return false;
}

void CompositeMenu::print() const
{
    std::cout << getName() << ", " << getDescription();
    std::cout << "---------------------" << std::endl;

    for (const auto &component : _menuComponents)
        component->print();
}
