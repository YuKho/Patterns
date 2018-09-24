#include "compositewaitress.h"
#include "menucomponent.h"
#include <utility>

CompositeWaitress::CompositeWaitress(std::shared_ptr<MenuComponent> allMenus)
    : _allMenus(std::move(allMenus))
{
}

void CompositeWaitress::printMenu() const
{
    _allMenus->print();
}
