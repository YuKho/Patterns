#ifndef MENU_H
#define MENU_H

class Iterator;

class Menu
{
public:
    virtual ~Menu() = default;
    virtual Iterator *createIterator() const = 0;
};

#endif // MENU_H
