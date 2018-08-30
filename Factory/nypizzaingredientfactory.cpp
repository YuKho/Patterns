#include "nypizzaingredientfactory.h"
#include "ingredients.h"

std::unique_ptr<Dough> NYPizzaIngredientFactory::createDought() const
{
    return std::make_unique<ThinCrustDough>("");
}

std::unique_ptr<Sauce> NYPizzaIngredientFactory::createSauce() const
{
    return std::make_unique<MarinaraSauce>("");
}

std::unique_ptr<Cheese> NYPizzaIngredientFactory::createCheese() const
{
    return std::make_unique<ReggianoCheese>("");
}

std::unique_ptr<Pepperoni> NYPizzaIngredientFactory::createPepperoni() const
{
    return std::make_unique<SlicedPepperoni>("");
}

std::unique_ptr<Clams> NYPizzaIngredientFactory::createClam() const
{
    return std::make_unique<FreshClams>("");
}

std::vector<std::unique_ptr<Veggies> > NYPizzaIngredientFactory::createVeggies() const
{
    return {std::make_unique<Garlic>(""), std::make_unique<Onion>(""),
            std::make_unique<Mushroom>(""), std::make_unique<RedPepper>("")};
}
