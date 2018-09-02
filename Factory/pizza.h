#ifndef PIZZA_H
#define PIZZA_H

#include "ingredients.h"
#include <string>
#include <vector>
#include <iosfwd>
#include <memory>

class Dough;
class Sauce;
class Cheese;
class Pepperoni;
class Clams;
class Veggies;

class PizzaIngredientFactory;

class Pizza
{
public:
    virtual ~Pizza() = default;

    void bake() const;
    void box() const;

    virtual void cut() const;
    virtual void prepare() = 0;

    std::string getName() const;
    void setName(std::string name);

    std::ostream &print(std::ostream &os) const;

    Pizza(std::string name, std::weak_ptr<PizzaIngredientFactory> factory);

protected:
    void createVeggies();
    void addTopping(std::string top);

protected:
    std::weak_ptr<PizzaIngredientFactory> _ingredientFactory;

    std::string _name;
    std::shared_ptr<Dough> _dough;
    std::shared_ptr<Sauce> _sauce;
    std::shared_ptr<Cheese> _cheese;
    std::shared_ptr<Pepperoni> _pepperoni;
    std::shared_ptr<Clams> _clam;
    std::vector<std::shared_ptr<Veggies>> _veggies;

private:
    std::vector<std::string> _toppings;
};

std::ostream &operator << (std::ostream &os, Pizza *pizza);

#endif // PIZZA_H
