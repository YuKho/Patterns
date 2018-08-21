#include "beverage.h"
#include <iostream>
#include <utility>

Beverage::Beverage(std::string description) : _description(std::move(description))
{
}

std::string Beverage::getDescription() const
{
    return _description;
}

DarkRoast::DarkRoast() : Beverage ("Dark Roast Coffee")
{
}

HouseBlend::HouseBlend() : Beverage ("House Blend Coffee")
{
}

Decaf::Decaf() : Beverage ("Decaf Coffee")
{
}

Espresso::Espresso() : Beverage ("Espresso")
{
}

CondimentDecorator::CondimentDecorator(std::shared_ptr<Beverage> beverage)
    : _beverage(std::move(beverage))
{
}

double Milk::cost() const
{
    return 0.10 + _beverage->cost();
}

std::string Milk::getDescription() const
{
    return _beverage->getDescription() + ", Milk";
}

double Mocha::cost() const
{
    return 0.20 + _beverage->cost();
}

std::string Mocha::getDescription() const
{
    return _beverage->getDescription() + ", Mocha";
}

double Soy::cost() const
{
    return 0.15 + _beverage->cost();
}

std::string Soy::getDescription() const
{
    return _beverage->getDescription() + ", Soy";
}

double Whip::cost() const
{
    return 0.10 + _beverage->cost();
}

std::string Whip::getDescription() const
{
    return _beverage->getDescription() + ", Whip";
}

std::ostream &operator <<(std::ostream &os, Beverage *beverage)
{
    return os << "Beverage: " << "'" << beverage->getDescription() << "'"
              << ", price: $" << beverage->cost();
}
