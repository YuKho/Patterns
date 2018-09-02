#include "pizzas.h"
#include "pizzaingredientfactory.h"

void CheesePizza::prepareImpl()
{
    _dough = _ingredientFactory.lock()->createDought();
    _sauce = _ingredientFactory.lock()->createSauce();
    _cheese = _ingredientFactory.lock()->createCheese();
}

void PepperoniPizza::prepareImpl()
{
    _dough = _ingredientFactory.lock()->createDought();
    _sauce = _ingredientFactory.lock()->createSauce();
    _cheese = _ingredientFactory.lock()->createCheese();
    _veggies = _ingredientFactory.lock()->createVeggies();
    _pepperoni = _ingredientFactory.lock()->createPepperoni();
}

void ClamPizza::prepareImpl()
{
    _dough = _ingredientFactory.lock()->createDought();
    _sauce = _ingredientFactory.lock()->createSauce();
    _cheese = _ingredientFactory.lock()->createCheese();
    _clam = _ingredientFactory.lock()->createClam();
}

void VeggiePizza::prepareImpl()
{
    _dough = _ingredientFactory.lock()->createDought();
    _sauce = _ingredientFactory.lock()->createSauce();
    _cheese = _ingredientFactory.lock()->createCheese();
    _veggies = _ingredientFactory.lock()->createVeggies();
}
