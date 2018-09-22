#ifndef PANCAKEHOUSEMENU_H
#define PANCAKEHOUSEMENU_H

#include "menu.h"
#include "menuitem.h"
#include <list>
#include <string>

class PancakeHouseMenu : public Menu
{
public:
    PancakeHouseMenu();
    void addItem(std::string name, std::string description, bool vegetarian, double price);

    std::unique_ptr<Iterator> createIterator() const  override;

private:
    std::list<MenuItem> _menuItems;
};

#endif // PANCAKEHOUSEMENU_H
