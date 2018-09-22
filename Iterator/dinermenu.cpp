#include "dinermenu.h"
#include "menuitem.h"
#include "dinermenuiterator.h"
#include <utility>
#include <iostream>

const size_t DinerMenu::MAX_ITEMS = 6;

DinerMenu::DinerMenu()
{    
    _menuItems = new MenuItem[MAX_ITEMS];

    addItem("Vegetarian BLT", "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99);
    addItem("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99);
    addItem("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29);
    addItem("Hotdog", "A hot dog, with saurkraut, relish, onions, topped with cheese", false, 3.05);
    addItem("Steamed Veggies and Brown Rice", "Steamed vegetables over brown rice", true, 3.99);
    addItem("Pasta", "Spaghetti with Marinara Sauce, and a slice of sourdough bread", true, 3.89);
}

void DinerMenu::addItem(std::string name, std::string description, bool vegetarian, double price)
{
    if (_numberOfItems >= MAX_ITEMS)
        std::cout << "Sorry, menu is full!  Can't add item to menu" << std::endl;
    else
        _menuItems[_numberOfItems++] = MenuItem(std::move(name), std::move(description), vegetarian,
                                                price);
}

std::unique_ptr<Iterator> DinerMenu::createIterator() const
{
    return std::make_unique<DinerMenuIterator>(_menuItems, MAX_ITEMS);
}

DinerMenu::~DinerMenu()
{
    delete [] _menuItems;
    _menuItems = nullptr;
}
