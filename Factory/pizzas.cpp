#include "pizzas.h"
#include "pizzaingredientfactory.h"
#include <iostream>

void CheesePizza::prepare() const
{
    std::cout << "Preparing " << getName();
    _ingredientFactory.lock()->createDought();
    _ingredientFactory.lock()->createSauce();
    _ingredientFactory.lock()->createCheese();
}

void PepperoniPizza::prepare() const
{
    _ingredientFactory.lock()->createDought();
    _ingredientFactory.lock()->createSauce();
    _ingredientFactory.lock()->createCheese();
}

void ClamPizza::prepare() const
{
    _ingredientFactory.lock()->createDought();
    _ingredientFactory.lock()->createSauce();
    _ingredientFactory.lock()->createCheese();
}

void VeggiePizza::prepare() const
{
    _ingredientFactory.lock()->createDought();
    _ingredientFactory.lock()->createSauce();
    _ingredientFactory.lock()->createCheese();
}
