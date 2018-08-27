#ifndef SIMPLEPIZZA_H
#define SIMPLEPIZZA_H

#include "../pizza.h"

class SimplePizzaPizza : public Pizza
{
protected:
    using Pizza::Pizza;

public:
    void cut() const override;
};

class CheesePizza : public SimplePizzaPizza
{
public:
    CheesePizza();
};

class PepperoniPizza : public SimplePizzaPizza
{
public:
    PepperoniPizza();
};

class ClamPizza : public SimplePizzaPizza
{
public:
    ClamPizza();
};

class VeggiePizza : public SimplePizzaPizza
{
public:
    VeggiePizza();
    void cut() const override;
};

#endif // SIMPLEPIZZA_H
