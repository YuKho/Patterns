#ifndef DUCKS_H
#define DUCKS_H

#include <iostream>

class SimpleDuck
{
public:
    virtual ~SimpleDuck() = default;
    virtual void quack() const = 0;
    virtual void fly() const = 0;
};

class SimpleMallardDuck : public SimpleDuck
{
public:
    void quack() const override
    {
        std::cout << "Quack" << std::endl;
    }

    void fly() const override
    {
        std::cout << "I'm flying" << std::endl;
    }
};

#endif // DUCKS_H
