#include "caffeinebeverage.h"
#include <iostream>

bool CaffeineBeverage::customerWantsCondiments() const
{
    return true;
}

void CaffeineBeverage::prepareRecipe()
{
    boilWater();
    brew();
    pourInCup();

    if (customerWantsCondiments())
    {
        std::cout << "[Customer wants condiments]" << std::endl;
        addCondiments();
    }
}

void CaffeineBeverage::boilWater() const
{
    std::cout << "Boiling water" << std::endl;
}

void CaffeineBeverage::pourInCup() const
{
    std::cout << "Pouring into cup" << std::endl;
}
