#ifndef COMPOSITEMENUITEM_H
#define COMPOSITEMENUITEM_H

#include "menucomponent.h"

class CompositeMenuItem : public MenuComponent
{
public:
    CompositeMenuItem(std::string name, std::string description, bool vegetarian, double price);
    void add(std::shared_ptr<MenuComponent> menuComponent) override;
    void remove(const std::shared_ptr<MenuComponent> &menuComponent) override;
    std::shared_ptr<MenuComponent> getChild(size_t index) override;
    std::string getName() const override;
    std::string getDescription() const override;
    double getPrice() const override;
    bool isVegetarian() const override;
    void print() const override;

private:
    std::string _name;
    std::string _description;
    bool _vegetarian;
    double _price;
};

#endif // COMPOSITEMENUITEM_H
