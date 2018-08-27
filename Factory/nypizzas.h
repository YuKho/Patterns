#ifndef NYPIZZAS_H
#define NYPIZZAS_H

#include "pizza.h"

class NYStylePizza : public Pizza
{
protected:
    using Pizza::Pizza;

public:
    void cut() const override;
};

class NYStyleCheesePizza : public NYStylePizza
{
public:
    NYStyleCheesePizza();
};

class NYStylePepperoniPizza : public NYStylePizza
{
public:
    NYStylePepperoniPizza();
};

class NYStyleClamPizza : public NYStylePizza
{
public:
    NYStyleClamPizza();
};

class NYStyleVeggiePizza : public NYStylePizza
{
public:
    NYStyleVeggiePizza();
};


#endif // NYPIZZAS_H
