#ifndef COMPOSITEMENUITEM_H
#define COMPOSITEMENUITEM_H

#include "menucomponent.h"

namespace Composite
{

class MenuItem : public MenuComponent
{
public:
    MenuItem(std::string name, std::string description, bool vegetarian, double price);

    double getPrice() const;
    bool isVegetarian() const;

    void print() const override;

    MenuItem *getMenuItem() override;
    const MenuItem *getMenuItem() const override;

private:
    bool _vegetarian;
    double _price;
};

} // end namespace Composite

#endif // COMPOSITEMENUITEM_H
