#ifndef PIZZAINGREDIENTFACTORY_H
#define PIZZAINGREDIENTFACTORY_H

#include <vector>
#include <memory>

class Dough;
class Sauce;
class Cheese;
class Pepperoni;
class Clams;
class Veggies;

class PizzaIngredientFactory
{
public:
    virtual ~PizzaIngredientFactory() = default;

    virtual std::unique_ptr<Dough> createDought() const = 0;
    virtual std::unique_ptr<Sauce> createSauce() const = 0;
    virtual std::unique_ptr<Cheese> createCheese() const = 0;
    virtual std::unique_ptr<Pepperoni> createPepperoni() const = 0;
    virtual std::unique_ptr<Clams> createClam() const = 0;
    virtual std::vector<std::shared_ptr<Veggies>> createVeggies() const = 0;
};

#endif // PIZZAINGREDIENTFACTORY_H
