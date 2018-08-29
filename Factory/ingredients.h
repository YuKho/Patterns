#ifndef INGREDIENTS_H
#define INGREDIENTS_H

// Abstract ingredients

class Dough
{
public:
    virtual ~Dough() = default;
};

class Sauce
{
public:
    virtual ~Sauce() = default;
};

class Cheese
{
public:
    virtual ~Cheese() = default;
};

class Clams
{
public:
    virtual ~Clams() = default;
};

// Concrete ingredients

class ThickCrustDough : public Dough
{

};

class ThinCrustDough : public Dough
{

};

class PlumTomatoSauce : public Sauce
{

};

class MarinaraSauce : public Sauce
{

};

class MozzarellaCheese : public Cheese
{

};

class ReggianoCheese : public Cheese
{

};

class FrozenClams : public Clams
{

};

class FreshClams : public Clams
{

};

#endif // INGREDIENTS_H
