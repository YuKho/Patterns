#ifndef BEVERAGES_H
#define BEVERAGES_H

#include "caffeinebeverage.h"

class Tea : public CaffeineBeverage
{
public:
    void brew() const override;
    void addCondiments() const override;
};

class Coffee : public CaffeineBeverage
{
public:
    void brew() const override;
    void addCondiments() const override;
};

#endif // BEVERAGES_H
