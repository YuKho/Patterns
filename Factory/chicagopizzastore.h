#ifndef CHICAGOPIZZASTORE_H
#define CHICAGOPIZZASTORE_H

#include "pizzastore.h"
#include "pizzas.h"
#include "chicagopizzaingredientfactory.h"
#include <memory>

class ChicagoPizzaStore : public PizzaStore
{
public:
    ChicagoPizzaStore() : PizzaStore{std::make_shared<ChicagoPizzaIngredientFactory>()} {}

private:
    // This method represent also 'Factory method' pattern.
    std::unique_ptr<Pizza> createPizza(const std::string &name) const override
    {
        switch (getPizzaType(name))
        {
        case PizzaType::Cheese:
            return std::make_unique<CheesePizza>("Chicago Style Cheese Pizza", _factory);

        case PizzaType::Pepperoni:
            return std::make_unique<PepperoniPizza>("Chicago Style Pepperoni Pizza", _factory);

        case PizzaType::Clam:
            return std::make_unique<ClamPizza>("Chicago Style Clam Pizza", _factory);

        case PizzaType::Veggie:
            return std::make_unique<VeggiePizza>("Chicago Style Veggie Pizza", _factory);

        default:
            return nullptr;
        }
    }
};

#endif // CHICAGOPIZZASTORE_H
