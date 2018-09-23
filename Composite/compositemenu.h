#ifndef COMPOSITEMENU_H
#define COMPOSITEMENU_H

#include "menucomponent.h"
#include <vector>

class CompositeMenu : public MenuComponent
{
public:
    CompositeMenu(std::string name, std::string description);
    void add(std::shared_ptr<MenuComponent> menuComponent) override;
    void remove(const std::shared_ptr<MenuComponent> &menuComponent) override;
    std::shared_ptr<MenuComponent> getChild(size_t index) override;
    std::string getName() const override;
    std::string getDescription() const override;
    double getPrice() const override;
    bool isVegetarian() const override;
    void print() const override;

private:
    std::vector<std::shared_ptr<MenuComponent>> _menuComponents;
    std::string _name;
    std::string _description;
};

#endif // COMPOSITEMENU_H
