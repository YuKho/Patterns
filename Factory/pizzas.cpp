#include "pizzas.h"
#include "pizzaingredientfactory.h"
#include <iostream>

void CheesePizza::prepare()
{
    std::cout << "Preparing " << getName();
    _dough = _ingredientFactory.lock()->createDought();
    _sauce = _ingredientFactory.lock()->createSauce();
    _cheese = _ingredientFactory.lock()->createCheese();
}

void PepperoniPizza::prepare()
{
    std::cout << "Preparing " << getName();
    _dough = _ingredientFactory.lock()->createDought();
    _sauce = _ingredientFactory.lock()->createSauce();
    _cheese = _ingredientFactory.lock()->createCheese();
    _veggies = _ingredientFactory.lock()->createVeggies();
    _pepperoni = _ingredientFactory.lock()->createPepperoni();
}

void ClamPizza::prepare()
{
    std::cout << "Preparing " << getName();
    _dough = _ingredientFactory.lock()->createDought();
    _sauce = _ingredientFactory.lock()->createSauce();
    _cheese = _ingredientFactory.lock()->createCheese();
    _clam = _ingredientFactory.lock()->createClam();
}

void VeggiePizza::prepare()
{
    std::cout << "Preparing " << getName();
    _dough = _ingredientFactory.lock()->createDought();
    _sauce = _ingredientFactory.lock()->createSauce();
    _cheese = _ingredientFactory.lock()->createCheese();
    _veggies = _ingredientFactory.lock()->createVeggies();
}
