#ifndef SIMPLEPIZZASTORE_H
#define SIMPLEPIZZASTORE_H

#include "simplepizzafactory.h"
#include <memory>
#include <string>

class Pizza;

class SimplePizzaStore
{
public:
    static std::unique_ptr<Pizza> orderPizza(const std::string &type)
    {
        auto pizza = SimplePizzaFactory::createPizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }
};

#endif // SIMPLEPIZZASTORE_H
