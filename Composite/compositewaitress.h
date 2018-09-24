#ifndef COMPOSITE_WAITRESS_H
#define COMPOSITE_WAITRESS_H

#include <memory>

class MenuComponent;

class CompositeWaitress final
{
public:
    explicit CompositeWaitress(std::shared_ptr<MenuComponent> allMenus);
    void printMenu() const;

private:
    std::shared_ptr<MenuComponent> _allMenus;
};

#endif // COMPOSITE_WAITRESS_H
