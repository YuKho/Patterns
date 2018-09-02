#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include "pizza.h"
#include <memory>
#include <string>

class PizzaIngredientFactory;
class Pizza;

class PizzaStore
{
public:
    enum class PizzaType { Cheese, Pepperoni, Clam, Veggie, Invalid };
    static PizzaType getPizzaType(const std::string &name);

public:
    virtual ~PizzaStore() = default;
    std::unique_ptr<Pizza> orderPizza(const std::string &name) const;

protected:
    explicit PizzaStore(std::shared_ptr<PizzaIngredientFactory> factory);

private:
    virtual std::unique_ptr<Pizza> createPizza(const std::string &name) const = 0;

protected:
    std::shared_ptr<PizzaIngredientFactory> _factory;
};

#endif // PIZZASTORE_H
