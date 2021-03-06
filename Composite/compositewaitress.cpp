#include "compositewaitress.h"
#include "menucomponent.h"
#include "compositemenu.h"
#include "compositemenuitem.h"
#include <utility>
#include <iostream>

Composite::Waitress::Waitress(std::shared_ptr<MenuComponent> allMenus)
    : _allMenus(std::move(allMenus))
{
}

void Composite::Waitress::printMenu() const
{
    _allMenus->print();

    std::cout << "\nTotal count of main menus: " << menuCount() << std::endl;
    std::cout << "Total count of sub menus: " << subMenuCount() << std::endl;
}

void Composite::Waitress::addMenu(const std::shared_ptr<MenuComponent> &menuComponent)
{
    if (_allMenus->getMenu())
        _allMenus->getMenu()->add(menuComponent);
}

void Composite::Waitress::removeMenu(const std::shared_ptr<Composite::MenuComponent> &menuComponent)
{
    if (_allMenus->getMenu())
        _allMenus->getMenu()->remove(menuComponent);
}

std::shared_ptr<Composite::MenuComponent> Composite::Waitress::getMenu(size_t index) const
{
    if (_allMenus->getMenu())
        return _allMenus->getMenu()->getChild(index);

    return nullptr;
}

size_t Composite::Waitress::menuCount() const
{
    if (_allMenus->getMenu())
        return _allMenus->getMenu()->menuCount();

    return 0;
}

size_t Composite::Waitress::subMenuCount() const
{
    if (_allMenus->getMenu())
        return _allMenus->getMenu()->subMenuCount();

    return 0;
}

std::unique_ptr<Composite::MenuComponent> Composite::Waitress::createMenu()
{
    auto pancakeHouseMenu = std::make_shared<Menu>("PANCAKE HOUSE MENU", "Breakfast");
    auto dinerMenu =        std::make_shared<Menu>("DINER MENU", "Lunch");
    auto cafeMenu =         std::make_shared<Menu>("CAFE MENU", "Dinner");
    auto dessertMenu =      std::make_shared<Menu>("DESSERT MENU", "Dessert of course!");
    auto coffeeMenu =       std::make_shared<Menu>("COFFEE MENU", "Stuff to go with your afternoon coffee");

    auto allMenus = std::make_unique<Menu>("ALL MENUS", "All menus combined");

    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);
    allMenus->add(cafeMenu);

    pancakeHouseMenu->add(std::make_shared<MenuItem>("K&B's Pancake Breakfast",
                          "Pancakes with scrambled eggs, and toast", true, 2.99));
    pancakeHouseMenu->add(std::make_shared<MenuItem>("Regular Pancake Breakfast",
                          "Pancakes with fried eggs, sausage", false, 2.99));
    pancakeHouseMenu->add(std::make_shared<MenuItem>("Blueberry Pancakes",
                          "Pancakes made with fresh blueberries, and blueberry syrup", true, 3.49));
    pancakeHouseMenu->add(std::make_shared<MenuItem>("Waffles",
                          "Waffles, with your choice of blueberries or strawberries", true, 3.59));

    dinerMenu->add(std::make_shared<MenuItem>("Vegetarian BLT",
                   "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99));
    dinerMenu->add(std::make_shared<MenuItem>("BLT",
                  "Bacon with lettuce & tomato on whole wheat", false, 2.99));
    dinerMenu->add(std::make_shared<MenuItem>("Soup of the day",
                   "A bowl of the soup of the day, with a side of potato salad", false, 3.29));
    dinerMenu->add(std::make_shared<MenuItem>("Hotdog",
                   "A hot dog, with saurkraut, relish, onions, topped with cheese", false, 3.05));
    dinerMenu->add(std::make_shared<MenuItem>("Steamed Veggies and Brown Rice",
                   "Steamed vegetables over brown rice", true, 3.99));
    dinerMenu->add(std::make_shared<MenuItem>("Pasta",
                   "Spaghetti with Marinara Sauce, and a slice of sourdough bread", true, 3.89));

    dinerMenu->add(dessertMenu);

    dessertMenu->add(std::make_shared<MenuItem>("Apple Pie",
                     "Apple pie with a flakey crust, topped with vanilla icecream", true, 1.59));
    dessertMenu->add(std::make_shared<MenuItem>("Cheesecake",
                     "Creamy New York cheesecake, with a chocolate graham crust", true, 1.99));
    dessertMenu->add(std::make_shared<MenuItem>("Sorbet",
                     "A scoop of raspberry and a scoop of lime", true, 1.89));
    cafeMenu->add(std::make_shared<MenuItem>("Veggie Burger and Air Fries",
                  "Veggie burger on a whole wheat bun, lettuce, tomato, and fries", true, 3.99));
    cafeMenu->add(std::make_shared<MenuItem>("Soup of the day",
                  "A cup of the soup of the day, with a side salad", false, 3.69));
    cafeMenu->add(std::make_shared<MenuItem>("Burrito",
                  "A large burrito, with whole pinto beans, salsa, guacamole", true, 4.29));

    cafeMenu->add(coffeeMenu);

    coffeeMenu->add(std::make_shared<MenuItem>("Coffee Cake",
                    "Crumbly cake topped with cinnamon and walnuts", true, 1.59));
    coffeeMenu->add(std::make_shared<MenuItem>("Bagel",
                    "Flavors include sesame, poppyseed, cinnamon raisin, pumpkin", false, 0.69));
    coffeeMenu->add(std::make_shared<MenuItem>("Biscotti",
                     "Three almond or hazelnut biscotti cookies", true, 0.89));

    return allMenus;
}
