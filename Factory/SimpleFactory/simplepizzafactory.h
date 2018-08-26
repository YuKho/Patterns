#ifndef SIMPLEPIZZAFACTORY_H
#define SIMPLEPIZZAFACTORY_H

#include "simplepizza.h"
#include <memory>
#include <string>

class SimplePizzaFactory
{
public:
    enum class PizzaType { Cheese, Pepperoni, Clam, Veggie, Invalid };

    static std::unique_ptr<Pizza> createPizza(const std::string &name)
    {
        switch (getPizzaType(name))
        {
        case PizzaType::Cheese:
            return std::make_unique<CheesePizza>();

        case PizzaType::Pepperoni:
            return std::make_unique<PepperoniPizza>();

        case PizzaType::Clam:
            return std::make_unique<ClamPizza>();

        case PizzaType::Veggie:
            return std::make_unique<VeggiePizza>();

        default:
            return nullptr;
        }
    }

private:
    static PizzaType getPizzaType(const std::string &name)
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
};

#endif // SIMPLEPIZZAFACTORY_H
