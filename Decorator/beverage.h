#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <iosfwd>
#include <string>
#include <memory>

class Beverage
{
public:
    explicit Beverage(std::string description);
    Beverage() = default;
    virtual ~Beverage() = default;
    virtual std::string getDescription() const;
    virtual double cost() const = 0;

protected:
    std::string _description{"Unknown Beverage"};
};

class CondimentDecorator : public Beverage
{
public:
    explicit CondimentDecorator(std::shared_ptr<Beverage> beverage);

protected:
    std::shared_ptr<Beverage> _beverage;
};

class DarkRoast : public Beverage
{
public:
    DarkRoast();
    double cost() const override { return 0.99; }
};

class HouseBlend : public Beverage
{
public:
    HouseBlend();
    double cost() const override { return 0.89; }
};

class Decaf : public Beverage
{
public:
    Decaf();
    double cost() const override { return 1.05; }
};

class Espresso : public Beverage
{
public:
    Espresso();
    double cost() const override { return 1.99; }
};

// Decorators:

class Milk : public CondimentDecorator
{
public:
    using CondimentDecorator::CondimentDecorator;

    double cost() const override;
    std::string getDescription() const override;
};

class Mocha : public CondimentDecorator
{
public:
    using CondimentDecorator::CondimentDecorator;

    double cost() const override;
    std::string getDescription() const override;
};

class Soy : public CondimentDecorator
{
public:
    using CondimentDecorator::CondimentDecorator;

    double cost() const override;
    std::string getDescription() const override;
};

class Whip : public CondimentDecorator
{
public:
    using CondimentDecorator::CondimentDecorator;

    double cost() const override;
    std::string getDescription() const override;
};

std::ostream &operator << (std::ostream &os, Beverage *beverage);

#endif // BEVERAGE_H
