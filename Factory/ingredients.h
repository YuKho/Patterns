#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <string>
#include <utility>
#include <cassert>

// Abstract ingredients

class Ingredient
{
public:
    virtual ~Ingredient() = default;
    std::string name() const { assert(!_ingredient.empty()); return _ingredient; }

protected:
    explicit Ingredient(std::string name) : _ingredient(std::move(name)) {}

private:
    std::string _ingredient;
};

class Dough : public Ingredient
{
protected:
    using Ingredient::Ingredient;
};

class Sauce : public Ingredient
{
protected:
    using Ingredient::Ingredient;
};

class Cheese : public Ingredient
{
protected:
    using Ingredient::Ingredient;
};

class Clams : public Ingredient
{
protected:
    using Ingredient::Ingredient;
};

class Veggies : public Ingredient
{
protected:
    using Ingredient::Ingredient;
};

class Pepperoni : public Ingredient
{
protected:
    using Ingredient::Ingredient;
};

// Concrete ingredients

class ThickCrustDough : public Dough
{
public:
    ThickCrustDough() : Dough("ThickCrust Dough") {}
};

class ThinCrustDough : public Dough
{
public:
    ThinCrustDough() : Dough("ThinCrust Dough") {}
};

class PlumTomatoSauce : public Sauce
{
public:
    PlumTomatoSauce() : Sauce("PlumTomato Sauce") {}
};

class MarinaraSauce : public Sauce
{
public:
    MarinaraSauce() : Sauce("Marinara Sauce") {}
};

class MozzarellaCheese : public Cheese
{
public:
    MozzarellaCheese() : Cheese("Mozzarella Cheese") {}
};

class ReggianoCheese : public Cheese
{
public:
    ReggianoCheese() : Cheese("Reggiano Cheese") {}
};

class FrozenClams : public Clams
{
public:
    FrozenClams() : Clams("Frozen Clams") {}
};

class FreshClams : public Clams
{
public:
    FreshClams() : Clams("Fresh Clams") {}
};

class Garlic : public Veggies
{
public:
    Garlic() : Veggies("Garlic") {}
};

class Onion : public Veggies
{
public:
    Onion() : Veggies("Onion") {}
};

class Mushroom : public Veggies
{
public:
    Mushroom() : Veggies("Mushroom") {}
};

class RedPepper : public Veggies
{
public:
    RedPepper() : Veggies("Red Pepper") {}
};

class BlackOlives : public Veggies
{
public:
    BlackOlives() : Veggies("Black Olives") {}
};

class Spinach : public Veggies
{
public:
    Spinach() : Veggies("Spinach") {}
};

class Eggplant : public Veggies
{
public:
    Eggplant() : Veggies("Eggplant") {}
};

class SlicedPepperoni : public Pepperoni
{
public:
    SlicedPepperoni() : Pepperoni("Sliced Pepperoni") {}
};

#endif // INGREDIENTS_H
