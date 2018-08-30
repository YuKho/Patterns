#ifndef CHICAGOPIZZAINGREDIENTFACTORY_H
#define CHICAGOPIZZAINGREDIENTFACTORY_H

#include "pizzaingredientfactory.h"

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    std::unique_ptr<Dough> createDought() const override;
    std::unique_ptr<Sauce> createSauce() const override;
    std::unique_ptr<Cheese> createCheese() const override;
    std::unique_ptr<Pepperoni> createPepperoni() const override;
    std::unique_ptr<Clams> createClam() const override;
    std::vector<std::unique_ptr<Veggies>> createVeggies() const override;
};

#endif // CHICAGOPIZZAINGREDIENTFACTORY_H
