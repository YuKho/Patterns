#ifndef COMPOSITEMENU_H
#define COMPOSITEMENU_H

#include "menucomponent.h"
#include <vector>

namespace Composite
{

class Menu : public MenuComponent
{
public:
    using MenuComponent::MenuComponent;

    void add(std::shared_ptr<MenuComponent> menuComponent);
    void remove(const std::shared_ptr<MenuComponent> &menuComponent);
    std::shared_ptr<Composite::MenuComponent> getChild(size_t index);

    void print() const override;

    Menu *getMenu() override;
    const Menu *getMenu() const override;

private:
    std::vector<std::shared_ptr<MenuComponent>> _menuComponents;
};

} // end namespace Composite

#endif // COMPOSITEMENU_H
