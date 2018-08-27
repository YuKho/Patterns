#ifndef CHICAGOPIZZASTORE_H
#define CHICAGOPIZZASTORE_H

#include "pizzastore.h"
#include "chicagopizzas.h"
#include <memory>

class ChicagoPizzaStore : public PizzaStore
{
private:
    std::unique_ptr<Pizza> createPizza(const std::string &name) const override
    {
        switch (getPizzaType(name))
        {
        case PizzaType::Cheese:
            return std::make_unique<ChicagoStyleCheesePizza>();

        case PizzaType::Pepperoni:
            return std::make_unique<ChicagoStylePepperoniPizza>();

        case PizzaType::Clam:
            return std::make_unique<ChicagoStyleClamPizza>();

        case PizzaType::Veggie:
            return std::make_unique<ChicagoStyleVeggiePizza>();

        default:
            return nullptr;
        }
    }
};

#endif // CHICAGOPIZZASTORE_H
