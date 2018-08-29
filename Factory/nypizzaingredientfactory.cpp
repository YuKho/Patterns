#include "nypizzaingredientfactory.h"

std::unique_ptr<Dough> NYPizzaIngredientFactory::createDought() const
{
    return nullptr;
}

std::unique_ptr<Sauce> NYPizzaIngredientFactory::createSauce() const
{
    return nullptr;
}

std::unique_ptr<Cheese> NYPizzaIngredientFactory::createCheese() const
{
    return nullptr;
}

std::unique_ptr<Pepperoni> NYPizzaIngredientFactory::createPepperoni() const
{
    return nullptr;
}

std::unique_ptr<Clam> NYPizzaIngredientFactory::createClam() const
{
    return nullptr;
}

std::vector<std::unique_ptr<Veggies> > NYPizzaIngredientFactory::createVeggies() const
{
    return {};
}
