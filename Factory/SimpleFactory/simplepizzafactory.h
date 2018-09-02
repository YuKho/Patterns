#ifndef SIMPLEPIZZAFACTORY_H
#define SIMPLEPIZZAFACTORY_H

#include "../pizzastore.h"
#include "simplepizza.h"
#include <memory>

class SimplePizzaFactory
{
public:
    static std::unique_ptr<SimplePizza> createPizza(const std::string &name)
    {
        switch (PizzaStore::getPizzaType(name))
        {
        case PizzaStore::PizzaType::Cheese:
            return std::make_unique<SimpleCheesePizza>();

        case PizzaStore::PizzaType::Pepperoni:
            return std::make_unique<SimplePepperoniPizza>();

        case PizzaStore::PizzaType::Clam:
            return std::make_unique<SimpleClamPizza>();

        case PizzaStore::PizzaType::Veggie:
            return std::make_unique<SimpleVeggiePizza>();

        default:
            return nullptr;
        }
    }
};

#endif // SIMPLEPIZZAFACTORY_H
