#ifndef WAITRESS_H
#define WAITRESS_H

#include <vector>
#include <memory>
#include <initializer_list>

class Menu;
class Iterator;

class Waitress final
{
public:
    Waitress() = default;
    explicit Waitress(std::initializer_list<std::shared_ptr<Menu>> menus);
    void printMenu() const;
    void printVegetarianMenu() const;
    void addMenu(std::shared_ptr<Menu> menu);

private:
    void printMenu(const std::shared_ptr<Iterator> &iterator) const;
    void printVegetarianMenu(const std::shared_ptr<Iterator> &iterator) const;

private:
    std::vector<std::shared_ptr<Menu>> _menus;
};

#endif // WAITRESS_H
