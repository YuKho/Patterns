#include "beverages.h"
#include <iostream>

void Tea::brew() const
{
    std::cout << "Steeping the tea" << std::endl;
}

void Tea::addCondiments() const
{
    std::cout << "Adding Lemon to the tea" << std::endl;
}

bool Tea::customerWantsCondiments() const
{
    return false;
}

void Coffee::brew() const
{
    std::cout << "Dripping Coffee through filter" << std::endl;
}

void Coffee::addCondiments() const
{
    std::cout << "Adding Sugar and Milk to the coffee" << std::endl;
}
