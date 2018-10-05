#ifndef SIMPLEPIZZASTORE_H
#define SIMPLEPIZZASTORE_H

#include "pizzafactory.h"
#include <memory>
#include <string>

namespace SimpleFactory
{

class Pizza;

class PizzaStore
{
public:
    static std::unique_ptr<Pizza> orderPizza(const std::string &type)
    {
        auto pizza = PizzaFactory::createPizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }
};

} // end namespace SimpleFactory

#endif // SIMPLEPIZZASTORE_H
