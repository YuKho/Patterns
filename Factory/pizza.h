#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <vector>
#include <iosfwd>

class Pizza
{
public:
    Pizza(std::string name, std::string dough, std::string sauce);
    virtual ~Pizza() = 0;

    virtual void cut() const;

    void prepare() const;
    void bake() const;
    void box() const;
    std::string getName() const;
    std::ostream &print(std::ostream &os) const;

protected:
    void addTopping(std::string top);

private:
    std::string _name;
    std::string _dough;
    std::string _sauce;
    std::vector<std::string> _toppings;
};

class NYStyleCheesePizza : public Pizza
{
public:
    NYStyleCheesePizza();
};

class ChicagoStyleCheesePizza : public Pizza
{
public:
    ChicagoStyleCheesePizza();
    void cut() const override;
};

class ChicagoStylePepperoniPizza : public Pizza
{
public:
    ChicagoStylePepperoniPizza();
    void cut() const override;
};

class ChicagoStyleClamPizza : public Pizza
{
public:
    ChicagoStyleClamPizza();
    void cut() const override;
};

class ChicagoStyleVeggiePizza : public Pizza
{
public:
    ChicagoStyleVeggiePizza();
    void cut() const override;
};

std::ostream &operator << (std::ostream &os, Pizza *pizza);

#endif // PIZZA_H
