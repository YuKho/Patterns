#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem
{
public:
    MenuItem() = default;
    MenuItem(std::string name, std::string description, bool vegetarian, double price);
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    bool isVegetarian() const;
    std::string toString() const;

private:
    std::string _name;
    std::string _description;
    bool _vegetarian = false;
    double _price = 0.0;
};

#endif // MENUITEM_H
