#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <vector>
#include <iosfwd>
#include <memory>

class PizzaIngredientFactory;

class Pizza
{
public:
    virtual ~Pizza() = default;
    virtual void cut() const = 0;

    void bake() const;
    void box() const;
    std::string getName() const;
    void setName(std::string name);
    std::ostream &print(std::ostream &os) const;

protected:
    Pizza() = default;
    Pizza(std::string name, std::string dough, std::string sauce);
    Pizza(std::weak_ptr<PizzaIngredientFactory> factory);
    void addTopping(std::string top);
    virtual void prepare() const = 0;

protected:
    std::weak_ptr<PizzaIngredientFactory> _ingredientFactory;

private:
    std::string _name;
    std::string _dough;
    std::string _sauce;
    std::vector<std::string> _toppings;
};

std::ostream &operator << (std::ostream &os, Pizza *pizza);

#endif // PIZZA_H
