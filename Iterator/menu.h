#ifndef MENU_H
#define MENU_H

#include <memory>

class Iterator;

class Menu
{
public:
    virtual ~Menu() = default;
    virtual std::unique_ptr<Iterator> createIterator() const = 0;
};

#endif // MENU_H
