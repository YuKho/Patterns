#ifndef MENUCOMPONENT_H
#define MENUCOMPONENT_H

#include <memory>
#include <string>
#include <cstddef>

class MenuComponent
{
public:
    virtual ~MenuComponent() = default;

    virtual void add(std::shared_ptr<MenuComponent> menuComponent) = 0;
    virtual void remove(const std::shared_ptr<MenuComponent> &menuComponent) = 0;
    virtual std::shared_ptr<MenuComponent> getChild(size_t index) = 0;
    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;
    virtual double getPrice() const = 0;
    virtual bool isVegetarian() const = 0;
    virtual void print() const = 0;
};

#endif // MENUCOMPONENT_H
