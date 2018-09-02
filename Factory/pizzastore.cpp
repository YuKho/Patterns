#include "pizzastore.h"
#include "pizza.h"
#include <iostream>
#include <utility>

std::unique_ptr<Pizza> PizzaStore::orderPizza(const std::string &name) const
{
    auto pizza = createPizza(name);

    std::cout << "--- Making a " + pizza->name() + " ---" << std::endl;
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    return pizza;
}

PizzaStore::PizzaStore(std::shared_ptr<PizzaIngredientFactory> factory)
    : _factory(std::move(factory))
{
}

PizzaStore::PizzaType PizzaStore::getPizzaType(const std::string &name)
{
    if (name == "cheese")
        return PizzaType::Cheese;

    if (name == "pepperoni")
        return PizzaType::Pepperoni;

    if (name == "clam")
        return PizzaType::Clam;

    if (name == "veggie")
        return PizzaType::Veggie;

    return PizzaType::Invalid;
}
