#ifndef PIZZA_H
#define PIZZA_H

#include "abstractpizza.h"
#include "ingredients.h"
#include <vector>
#include <memory>

class PizzaIngredientFactory;

class Pizza : public AbstractPizza
{
public:
    Pizza(std::string name, std::weak_ptr<PizzaIngredientFactory> factory);

    void prepare() override;
    std::ostream& print(std::ostream &os) const override;

private:
    virtual void prepareImpl() = 0;

protected:
    std::weak_ptr<PizzaIngredientFactory> _ingredientFactory;

    std::shared_ptr<Dough> _dough;
    std::shared_ptr<Sauce> _sauce;
    std::shared_ptr<Cheese> _cheese;
    std::shared_ptr<Pepperoni> _pepperoni;
    std::shared_ptr<Clams> _clam;
    std::vector<std::shared_ptr<Veggies>> _veggies;
};

#endif // PIZZA_H
