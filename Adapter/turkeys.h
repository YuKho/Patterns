#ifndef TURKEYS_H
#define TURKEYS_H

#include <iostream>

class Turkey
{
public:
    virtual ~Turkey() = default;
    virtual void gobble() const = 0;
    virtual void fly() const = 0;
};

class WildTurkey : public Turkey
{
public:
    void gobble() const override
    {
        std::cout << "Gobble gobble" << std::endl;
    }

    void fly() const override
    {
        std::cout << "I'm flying a short distance" << std::endl;
    }
};

#endif // TURKEYS_H
