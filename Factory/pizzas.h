#ifndef PIZZAS_H
#define PIZZAS_H

#include "pizza.h"

class CheesePizza : public Pizza
{
public:
    using Pizza::Pizza;

private:
    void prepareImpl() override;
};

class PepperoniPizza : public Pizza
{
public:
    using Pizza::Pizza;

private:
    void prepareImpl() override;
};

class ClamPizza : public Pizza
{
public:
    using Pizza::Pizza;

private:
    void prepareImpl() override;
};

class VeggiePizza : public Pizza
{
public:
    using Pizza::Pizza;

private:
    void prepareImpl() override;
};

#endif // PIZZAS_H
