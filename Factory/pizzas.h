#ifndef PIZZAS_H
#define PIZZAS_H

#include "pizza.h"
#include <memory>

class PizzaIngredientFactory;

class CheesePizza : public Pizza
{
public:
    using Pizza::Pizza;

private:
    void prepare() override;
};

class PepperoniPizza : public Pizza
{
public:
    using Pizza::Pizza;

private:
    void prepare() override;
};

class ClamPizza : public Pizza
{
public:
    using Pizza::Pizza;

private:
    void prepare() override;
};

class VeggiePizza : public Pizza
{
public:
    using Pizza::Pizza;

private:
    void prepare() override;
};

#endif // PIZZAS_H
