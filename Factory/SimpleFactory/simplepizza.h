#ifndef SIMPLEPIZZA_H
#define SIMPLEPIZZA_H

#include <string>
#include <vector>
#include <iosfwd>

class SimplePizza
{
public:
    virtual ~SimplePizza() = default;
    virtual void cut() const;
    virtual void prepare() const;
    virtual void bake() const;
    virtual void box() const;

    std::ostream &print(std::ostream &os) const;

protected:
    SimplePizza(std::string name, std::string dough, std::string sauce);
    void addTopping(std::string top);

protected:
    std::string _name;
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

std::ostream &operator << (std::ostream &os, SimplePizza *pizza);

#endif // SIMPLEPIZZA_H
