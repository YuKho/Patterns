#ifndef NYPIZZASTORE_H
#define NYPIZZASTORE_H

#include "pizzastore.h"
#include "pizzas.h"
#include "nypizzaingredientfactory.h"
#include <memory>

class NYPizzaStore : public PizzaStore
{
public:
    NYPizzaStore() : PizzaStore{std::make_shared<NYPizzaIngredientFactory>()} {}

private:
    std::unique_ptr<Pizza> createPizza(const std::string &name) const override
    {
        switch (getPizzaType(name))
        {
        case PizzaType::Cheese:
            return std::make_unique<CheesePizza>("New York Style Cheese Pizza", _factory);

        case PizzaType::Pepperoni:
            return std::make_unique<PepperoniPizza>("New York Style Pepperoni Pizza", _factory);

        case PizzaType::Clam:
            return std::make_unique<ClamPizza>("New York Style Clam Pizza", _factory);

        case PizzaType::Veggie:
            return std::make_unique<VeggiePizza>("New York Style Veggie Pizza", _factory);

        default:
            return nullptr;
        }
    }
};

#endif // NYPIZZASTORE_H
