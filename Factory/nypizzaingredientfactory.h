#ifndef NYPIZZAINGREDIENTFACTORY_H
#define NYPIZZAINGREDIENTFACTORY_H

#include "pizzaingredientfactory.h"

class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
protected:
    std::unique_ptr<Dough> createDought() const override;
    std::unique_ptr<Sauce> createSauce() const override;
    std::unique_ptr<Cheese> createCheese() const override;
    std::unique_ptr<Pepperoni> createPepperoni() const override;
    std::unique_ptr<Clam> createClam() const override;
    std::vector<std::unique_ptr<Veggies>> createVeggies() const override;
};

#endif // NYPIZZAINGREDIENTFACTORY_H
