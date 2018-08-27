#include "chicagopizzas.h"
#include <iostream>

void ChicagoStylePizza::cut() const
{
    std::cout << "Cutting the \'" << getName() << "\' into square slices." << std::endl;
}

ChicagoStyleCheesePizza::ChicagoStyleCheesePizza()
    : ChicagoStylePizza("Chicago Style Deep Dish Cheese Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce")
{
    addTopping("Shredded Mozzarella Cheese");
}

ChicagoStylePepperoniPizza::ChicagoStylePepperoniPizza()
    : ChicagoStylePizza("Chicago Style Pepperoni Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce")
{
    addTopping("Shredded Mozzarella Cheese");
    addTopping("Black Olives");
    addTopping("Spinach");
    addTopping("Eggplant");
    addTopping("Sliced Pepperoni");
}

ChicagoStyleClamPizza::ChicagoStyleClamPizza()
    : ChicagoStylePizza("Chicago Style Clam Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce")
{
    addTopping("Shredded Mozzarella Cheese");
    addTopping("Frozen Clams from Chesapeake Bay");
}

ChicagoStyleVeggiePizza::ChicagoStyleVeggiePizza()
    : ChicagoStylePizza("Chicago Deep Dish Veggie Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce")
{
    addTopping("Shredded Mozzarella Cheese");
    addTopping("Black Olives");
    addTopping("Spinach");
    addTopping("Eggplant");
}

void ChicagoStyleVeggiePizza::cut() const
{
    std::cout << "Cutting the \'" << getName() << "\' into triangle form." << std::endl;
}
