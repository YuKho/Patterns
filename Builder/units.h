#ifndef UNITS_H
#define UNITS_H

#include <iostream>

class Unit
{
public:
    explicit Unit(int strength) : _strength(strength) {}
    virtual ~Unit() = default;
    virtual void info() const = 0;

protected:
    int _strength = 0;
};

class Infantryman : public Unit
{
public:
    using Unit::Unit;
    void info() const override { std::cout << "Infantryman: " << _strength << std::endl; }
};

class Archer : public Unit
{
public:
    using Unit::Unit;
    void info() const override { std::cout << "Archer: " << _strength << std::endl; }
};

class Horseman : public Unit
{
public:
    using Unit::Unit;
    void info() const override { std::cout << "Horseman: " << _strength << std::endl; }
};

class Catapult : public Unit
{
public:
    using Unit::Unit;
    void info() const override { std::cout << "Catapult: " << _strength << std::endl; }
};

class Elephant : public Unit
{
public:
    using Unit::Unit;
    void info() const override { std::cout << "Elephant: " << _strength << std::endl; }
};

#endif // UNITS_H
