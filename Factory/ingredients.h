#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <string>
#include <utility>

// Abstract ingredients

class Ingredient
{
public:
    explicit Ingredient(std::string name) : _ingredient(std::move(name)) {}
    virtual ~Ingredient() = default;
    std::string name() const { return _ingredient; }

private:
    std::string _ingredient;
};

class Dough : public Ingredient
{
public:
    using Ingredient::Ingredient;
};

class Sauce : public Ingredient
{
public:
    using Ingredient::Ingredient;
};

class Cheese : public Ingredient
{
public:
    using Ingredient::Ingredient;
};

class Clams : public Ingredient
{
public:
    using Ingredient::Ingredient;
};

class Veggies : public Ingredient
{
public:
    using Ingredient::Ingredient;
};

class Pepperoni : public Ingredient
{
public:
    using Ingredient::Ingredient;
};

// Concrete ingredients

class ThickCrustDough : public Dough
{
public:
    using Dough::Dough;
};

class ThinCrustDough : public Dough
{
public:
    using Dough::Dough;
};

class PlumTomatoSauce : public Sauce
{
public:
    using Sauce::Sauce;
};

class MarinaraSauce : public Sauce
{
public:
    using Sauce::Sauce;
};

class MozzarellaCheese : public Cheese
{
public:
    using Cheese::Cheese;
};

class ReggianoCheese : public Cheese
{
public:
    using Cheese::Cheese;
};

class FrozenClams : public Clams
{
public:
    using Clams::Clams;
};

class FreshClams : public Clams
{
public:
    using Clams::Clams;
};

class Garlic : public Veggies
{
public:
    using Veggies::Veggies;
};

class Onion : public Veggies
{
public:
    using Veggies::Veggies;
};

class Mushroom : public Veggies
{
public:
    using Veggies::Veggies;
};

class RedPepper : public Veggies
{
public:
    using Veggies::Veggies;
};

class BlackOlives : public Veggies
{
public:
    using Veggies::Veggies;
};

class Spinach : public Veggies
{
public:
    using Veggies::Veggies;
};

class Eggplant : public Veggies
{
public:
    using Veggies::Veggies;
};

class SlicedPepperoni : public Pepperoni
{
public:
    using Pepperoni::Pepperoni;
};

#endif // INGREDIENTS_H
