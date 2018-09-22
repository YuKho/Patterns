#include "waitress.h"
#include "iterator.h"
#include "menu.h"
#include <iostream>
#include <cstdio>

Waitress::Waitress(std::initializer_list<std::shared_ptr<Menu>> menus)
    : _menus(menus)
{
}

void Waitress::printMenu() const
{
    puts("MENU:\n");

    for (const auto &menu : _menus)
        printMenu(menu->createIterator());
}

void Waitress::printVegetarianMenu() const
{
    puts("VEGETARIAN MENU:\n");

    for (const auto &menu : _menus)
        printVegetarianMenu(menu->createIterator());
}

void Waitress::addMenu(std::shared_ptr<Menu> menu)
{
    _menus.push_back(std::move(menu));
}

void Waitress::printMenu(const std::shared_ptr<Iterator> &iterator) const
{
    while (iterator->hasNext())
    {
        MenuItem menuItem = iterator->next();
        std::cout << menuItem.toString() << std::endl;
    }
}

void Waitress::printVegetarianMenu(const std::shared_ptr<Iterator> &iterator) const
{
    while (iterator->hasNext())
    {
        MenuItem menuItem = iterator->next();
        if (menuItem.isVegetarian())
            std::cout << menuItem.toString() << std::endl;
    }
}
