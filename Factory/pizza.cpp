#include "pizza.h"
#include <iostream>

Pizza::~Pizza() = default;

Pizza::Pizza(std::string name, std::string dough, std::string sauce)
    : _name(std::move(name)), _dough(std::move(dough)), _sauce(std::move(sauce))
{
}

void Pizza::prepare() const
{
    std::cout << "Preparing \'" << _name << "\'...\n";
    std::cout << "Tossing dough...\n";
    std::cout << "Adding sauce...\n";
    std::cout << "Adding toppings:\n";
    for (const auto &top : _toppings)
        std::cout << "  " << top << "\n";

    std::cout << "Preparing \'" << _name << "\' finished." << std::endl;
}

void Pizza::bake() const
{
    std::cout << "Bake for 25 minutes at 350" << std::endl;
}

void Pizza::cut() const
{
    std::cout << "Cutting the pizza into diagonal slices" << std::endl;
}

void Pizza::box() const
{
    std::cout << "Place pizza in official PizzaStore box" << std::endl;
}

std::string Pizza::getName() const
{
    return _name;
}

std::ostream &Pizza::print(std::ostream &os) const
{
    os << "---- " << _name << " ----\n"
       << _dough << "\n"
       << _sauce << "\n";

    for (const auto &top : _toppings)
        os << top << "\n";

    return os;
}

void Pizza::addTopping(std::string top)
{
    _toppings.push_back(std::move(top));
}

NYStyleCheesePizza::NYStyleCheesePizza()
    : Pizza("NY Style Sauce and Cheese Pizza", "Thin Crust Dough", "Marianara Sauce")
{
    addTopping("Grated Reggiano Cheese");
}

ChicagoStyleCheesePizza::ChicagoStyleCheesePizza()
    : Pizza("Chicago Style Deep Dish Cheese Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce")
{
    addTopping("Shredded Mozzarella Cheese");
}

void ChicagoStyleCheesePizza::cut() const
{
    std::cout << "Cutting the pizza into square slices" << std::endl;
}

std::ostream &operator <<(std::ostream &os, Pizza *pizza)
{
    return pizza->print(os);
}

ChicagoStylePepperoniPizza::ChicagoStylePepperoniPizza()
    : Pizza("Chicago Style Pepperoni Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce")
{
    addTopping("Shredded Mozzarella Cheese");
    addTopping("Black Olives");
    addTopping("Spinach");
    addTopping("Eggplant");
    addTopping("Sliced Pepperoni");
}

void ChicagoStylePepperoniPizza::cut() const
{
    std::cout << "Cutting the pizza into square slices" << std::endl;
}

ChicagoStyleClamPizza::ChicagoStyleClamPizza()
    : Pizza("Chicago Style Clam Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce")
{
    addTopping("Shredded Mozzarella Cheese");
    addTopping("Frozen Clams from Chesapeake Bay");
}

void ChicagoStyleClamPizza::cut() const
{
    std::cout << "Cutting the pizza into square slices" << std::endl;
}

ChicagoStyleVeggiePizza::ChicagoStyleVeggiePizza()
    : Pizza ("Chicago Deep Dish Veggie Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce")
{
    addTopping("Shredded Mozzarella Cheese");
    addTopping("Black Olives");
    addTopping("Spinach");
    addTopping("Eggplant");
}

void ChicagoStyleVeggiePizza::cut() const
{
    std::cout << "Cutting the pizza into square slices" << std::endl;
}
