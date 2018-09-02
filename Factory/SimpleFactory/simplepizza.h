#ifndef SIMPLEPIZZA_H
#define SIMPLEPIZZA_H

#include "../abstractpizza.h"
#include <string>
#include <vector>
#include <iosfwd>

class SimplePizza : public AbstractPizza
{
public:
    void prepare() const override;
    std::ostream& print(std::ostream &os) const override;

protected:
    SimplePizza(std::string name, std::string dough, std::string sauce);
    void addTopping(std::string top);

protected:
    std::string _dough;
    std::string _sauce;
    std::vector<std::string> _toppings;
};

class SimpleCheesePizza : public SimplePizza
{
public:
    SimpleCheesePizza();
};

class SimplePepperoniPizza : public SimplePizza
{
public:
    SimplePepperoniPizza();
};

class SimpleClamPizza : public SimplePizza
{
public:
    SimpleClamPizza();
};

class SimpleVeggiePizza : public SimplePizza
{
public:
    SimpleVeggiePizza();
    void cut() const override;
};

#endif // SIMPLEPIZZA_H
