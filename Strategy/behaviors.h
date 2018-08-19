#ifndef BEHAVIORS_H
#define BEHAVIORS_H

#include <cstdio>

class FlyBehavior
{
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() = default;
};

class FlyWithWings : public FlyBehavior
{
public:
    void fly() override { puts("I'm flying!!"); }
};

class FlyNoWay : public FlyBehavior
{
public:
    void fly() override { puts("I can't fly"); }
};

class FlyRocketPowered : public FlyBehavior
{
public:
    void fly() override { puts("I'm flying with a rocket!"); }
};

///////////////////////////////////////////////////////////////////////////////////////////////////

class QuackBehavior
{
public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() = default;
};

class Quack : public QuackBehavior
{
public:
    void quack() override { puts("Quack"); }
};

class MuteQuack : public QuackBehavior
{
public:
    void quack() override { puts("<< Silence >>"); }
};

class Squeak : public QuackBehavior
{
public:
    void quack() override { puts("Squeak"); }
};

#endif // BEHAVIORS_H
