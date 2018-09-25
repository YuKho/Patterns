#include "compositemenu.h"
#include <utility>
#include <iostream>
#include <algorithm>

void Composite::Menu::add(std::shared_ptr<MenuComponent> menuComponent)
{
    _menuComponents.push_back(std::move(menuComponent));
}

void Composite::Menu::remove(const std::shared_ptr<MenuComponent> &menuComponent)
{
    auto it = std::find(_menuComponents.cbegin(), _menuComponents.cend(), menuComponent);
    if (it != _menuComponents.cend())
        _menuComponents.erase(it);
}

std::shared_ptr<Composite::MenuComponent> Composite::Menu::getChild(size_t index)
{
    if (index >= _menuComponents.size())
        return nullptr;

    return _menuComponents[index];
}

size_t Composite::Menu::menuCount() const
{
    size_t count = 0;
    for (const auto &component : _menuComponents)
    {
        if (component->getMenu())
            ++count;
    }

    return count;
}

size_t Composite::Menu::subMenuCount() const
{
    size_t count = 1;
    for (const auto &component : _menuComponents)
    {
        if (component->getMenu())
            count += component->getMenu()->subMenuCount();
    }

    return count;
}

void Composite::Menu::print() const
{
    std::cout << getName() << ", " << getDescription();
    std::cout << "---------------------" << std::endl;

    for (const auto &component : _menuComponents)
        component->print();
}

Composite::Menu *Composite::Menu::getMenu()
{
    return this;
}

const Composite::Menu *Composite::Menu::getMenu() const
{
    return this;
}
