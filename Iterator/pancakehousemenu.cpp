#include "pancakehousemenu.h"
#include "pancakehousemenuiterator.h"

PancakeHouseMenu::PancakeHouseMenu()
{
    addItem("K&B's Pancake Breakfast", "Pancakes with scrambled eggs, and toast", true, 2.99);
    addItem("Regular Pancake Breakfast", "Pancakes with fried eggs, sausage", false, 2.99);
    addItem("Blueberry Pancakes", "Pancakes made with fresh blueberries", true, 3.49);
    addItem("Waffles", "Waffles, with your choice of blueberries or strawberries", true, 30.59);
}

void PancakeHouseMenu::addItem(std::string name, std::string description, bool vegetarian, double price)
{
    _menuItems.emplace_back(std::move(name), std::move(description), vegetarian, price);
}

std::unique_ptr<Iterator> PancakeHouseMenu::createIterator() const
{
    return std::make_unique<PancakeHouseMenuIterator>(_menuItems);
}
