#ifndef SIMPLEPIZZA_H
#define SIMPLEPIZZA_H

#include "../abstractpizza.h"
#include <string>
#include <vector>

namespace SimpleFactory
{

class Pizza : public AbstractPizza
{
public:
    void prepare() override;
    std::ostream& print(std::ostream &os) const override;

protected:
    Pizza(std::string name, std::string dough, std::string sauce);
    void addTopping(std::string top);

protected:
    std::string _dough;
    std::string _sauce;
    std::vector<std::string> _toppings;
};

class CheesePizza : public Pizza
{
public:
    CheesePizza();
};

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza();
};

class ClamPizza : public Pizza
{
public:
    ClamPizza();
};

class VeggiePizza : public Pizza
{
public:
    VeggiePizza();
    void cut() const override;
};

} // end namespace SimpleFactory

#endif // SIMPLEPIZZA_H
