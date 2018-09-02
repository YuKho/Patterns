#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include "pizza.h"
#include <memory>
#include <string>
#include <iostream>

class PizzaStore
{
public:
    enum class PizzaType { Cheese, Pepperoni, Clam, Veggie, Invalid };

public:
    virtual ~PizzaStore() = default;

    std::unique_ptr<Pizza> orderPizza(const std::string &name) const
    {
        auto pizza = createPizza(name);

        std::cout << "--- Making a " + pizza->name() + " ---" << std::endl;
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }

protected:
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

private:
    virtual std::unique_ptr<Pizza> createPizza(const std::string &name) const = 0;
};

#endif // PIZZASTORE_H
