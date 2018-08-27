#ifndef CHICAGOPIZZAS_H
#define CHICAGOPIZZAS_H

#include "pizza.h"

class ChicagoStylePizza : public Pizza
{
protected:
    using Pizza::Pizza;

public:
    void cut() const override;
};

class ChicagoStyleCheesePizza : public ChicagoStylePizza
{
public:
    ChicagoStyleCheesePizza();
};

class ChicagoStylePepperoniPizza : public ChicagoStylePizza
{
public:
    ChicagoStylePepperoniPizza();
};

class ChicagoStyleClamPizza : public ChicagoStylePizza
{
public:
    ChicagoStyleClamPizza();
};

class ChicagoStyleVeggiePizza : public ChicagoStylePizza
{
public:
    ChicagoStyleVeggiePizza();
    void cut() const override;
};

#endif // CHICAGOPIZZAS_H
