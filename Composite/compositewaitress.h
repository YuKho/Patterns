#ifndef COMPOSITE_WAITRESS_H
#define COMPOSITE_WAITRESS_H

#include <memory>
#include <cstddef>

namespace Composite
{

class MenuComponent;

class Waitress final
{
public:
    explicit Waitress(std::shared_ptr<MenuComponent> allMenus);
    void printMenu() const;
    void addMenu(const std::shared_ptr<MenuComponent> &menuComponent);
    void removeMenu(const std::shared_ptr<MenuComponent> &menuComponent);
    std::shared_ptr<Composite::MenuComponent> getMenu(size_t index) const;
    size_t menuCount() const;
    size_t subMenuCount() const;

    static std::unique_ptr<Composite::MenuComponent> createMenu();

private:
    std::shared_ptr<MenuComponent> _allMenus;
};

} // end namespace Composite

#endif // COMPOSITE_WAITRESS_H
