#include "pizzas.h"
#include "pizzaingredientfactory.h"

void CheesePizza::prepareImpl()
{
    const auto factory = _ingredientFactory.lock();
    _dough = factory->createDought();
    _sauce = factory->createSauce();
    _cheese = factory->createCheese();
}

void PepperoniPizza::prepareImpl()
{
    const auto factory = _ingredientFactory.lock();
    _dough = factory->createDought();
    _sauce = factory->createSauce();
    _cheese = factory->createCheese();
    _veggies = factory->createVeggies();
    _pepperoni = factory->createPepperoni();
}

void ClamPizza::prepareImpl()
{
    const auto factory = _ingredientFactory.lock();
    _dough = factory->createDought();
    _sauce = factory->createSauce();
    _cheese = factory->createCheese();
    _clam = factory->createClam();
}

void VeggiePizza::prepareImpl()
{
    const auto factory = _ingredientFactory.lock();
    _dough = factory->createDought();
    _sauce = factory->createSauce();
    _cheese = factory->createCheese();
    _veggies = factory->createVeggies();
}
