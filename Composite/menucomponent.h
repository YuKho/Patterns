#ifndef MENUCOMPONENT_H
#define MENUCOMPONENT_H

#include <memory>
#include <string>
#include <cstddef>
#include <utility>

namespace Composite
{

class Menu;
class MenuItem;

class MenuComponent
{
public:
    MenuComponent(std::string name, std::string description)
        : _name(std::move(name)), _description(std::move(description))
    {}

    virtual ~MenuComponent() = default;

    std::string getName() const { return _name; }
    std::string getDescription() const { return _description; }

    virtual void print() const = 0;

    virtual Menu *getMenu() { return nullptr; }
    virtual const Menu *getMenu() const { return nullptr; }

    virtual MenuItem *getMenuItem() { return nullptr; }
    virtual const MenuItem *getMenuItem() const { return nullptr; }

protected:
    std::string _name;
    std::string _description;
};

} // end namespace Composite

#endif // MENUCOMPONENT_H
