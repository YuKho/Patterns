#ifndef NYPIZZASTORE_H
#define NYPIZZASTORE_H

#include "pizzastore.h"
#include "pizzas.h"
#include "nypizzaingredientfactory.h"
#include <memory>

class NYPizzaStore : public PizzaStore
{
public:
    NYPizzaStore() : _factory{std::make_shared<NYPizzaIngredientFactory>()} {}

private:
    std::unique_ptr<Pizza> createPizza(const std::string &name) const override
    {
        std::unique_ptr<Pizza> pizza;

        switch (getPizzaType(name))
        {
        case PizzaType::Cheese:
            pizza = std::make_unique<CheesePizza>(_factory);
            pizza->setName("");
            return pizza;

        case PizzaType::Pepperoni:
            pizza = std::make_unique<PepperoniPizza>(_factory);
            pizza->setName("");
            return pizza;

        case PizzaType::Clam:
            pizza = std::make_unique<ClamPizza>(_factory);
            pizza->setName("");
            return pizza;

        case PizzaType::Veggie:
            pizza = std::make_unique<VeggiePizza>(_factory);
            pizza->setName("");
            return pizza;

        default:
            return nullptr;
        }
    }

private:
    std::shared_ptr<PizzaIngredientFactory> _factory;
};

#endif // NYPIZZASTORE_H
