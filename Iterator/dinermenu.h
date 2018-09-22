#ifndef DINERMENU_H
#define DINERMENU_H

#include "menu.h"
#include <string>
#include <cstddef>

class MenuItem;

class DinerMenu : public Menu
{
public:
    DinerMenu();
    void addItem(std::string name, std::string description, bool vegetarian, double price);

    std::unique_ptr<Iterator> createIterator() const override;
    ~DinerMenu() override;

private:
    static const size_t MAX_ITEMS;

    size_t _numberOfItems = 0;
    MenuItem *_menuItems = nullptr;
};

#endif // DINERMENU_H
