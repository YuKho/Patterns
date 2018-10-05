#ifndef PIZZAFACTORY_H
#define PIZZAFACTORY_H

#include "../pizzastore.h"
#include "simplepizza.h"
#include <memory>

class PizzaFactory
{
public:
    static std::unique_ptr<SimpleFactory::Pizza> createPizza(const std::string &name)
    {
        switch (PizzaStore::getPizzaType(name))
        {
        case PizzaStore::PizzaType::Cheese:
            return std::make_unique<SimpleFactory::CheesePizza>();

        case PizzaStore::PizzaType::Pepperoni:
            return std::make_unique<SimpleFactory::PepperoniPizza>();

        case PizzaStore::PizzaType::Clam:
            return std::make_unique<SimpleFactory::ClamPizza>();

        case PizzaStore::PizzaType::Veggie:
            return std::make_unique<SimpleFactory::VeggiePizza>();

        default:
            return nullptr;
        }
    }
};

#endif // PIZZAFACTORY_H
