#include "chicagopizzaingredientfactory.h"
#include "ingredients.h"

std::unique_ptr<Dough> ChicagoPizzaIngredientFactory::createDought() const
{
    return std::make_unique<ThickCrustDough>();
}

std::unique_ptr<Sauce> ChicagoPizzaIngredientFactory::createSauce() const
{
    return std::make_unique<PlumTomatoSauce>();
}

std::unique_ptr<Cheese> ChicagoPizzaIngredientFactory::createCheese() const
{
    return std::make_unique<MozzarellaCheese>();
}

std::unique_ptr<Pepperoni> ChicagoPizzaIngredientFactory::createPepperoni() const
{
    return std::make_unique<SlicedPepperoni>();
}

std::unique_ptr<Clams> ChicagoPizzaIngredientFactory::createClam() const
{
    return std::make_unique<FrozenClams>();
}

std::vector<std::unique_ptr<Veggies> > ChicagoPizzaIngredientFactory::createVeggies() const
{
    return {std::make_unique<BlackOlives>(), std::make_unique<Spinach>(),
            std::make_unique<Eggplant>()};
}
