#ifndef NYPIZZASTORE_H
#define NYPIZZASTORE_H

#include "pizzastore.h"
#include "nypizzas.h"
#include <memory>

class NYPizzaStore : public PizzaStore
{
private:
    std::unique_ptr<Pizza> createPizza(const std::string &name) const override
    {
        switch (getPizzaType(name))
        {
        case PizzaType::Cheese:
            return std::make_unique<NYStyleCheesePizza>();

        case PizzaType::Pepperoni:
            return std::make_unique<NYStylePepperoniPizza>();

        case PizzaType::Clam:
            return std::make_unique<NYStyleClamPizza>();

        case PizzaType::Veggie:
            return std::make_unique<NYStyleVeggiePizza>();

        default:
            return nullptr;
        }
    }
};

#endif // NYPIZZASTORE_H
