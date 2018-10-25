#include "army.h"
#include <utility>
#include <iostream>

Army::~Army() = default;

Army::Army(std::string name) : _armyName(std::move(name))
{}

void Army::addInfantryman(Infantryman infantryman)
{
    vi.push_back(std::move(infantryman));
}

void Army::addArcher(Archer archer)
{
    va.push_back(std::move(archer));
}

void Army::addHorseman(Horseman horseman)
{
    vh.push_back(std::move(horseman));
}

void Army::addCatapult(Catapult catapult)
{
    vc.push_back(std::move(catapult));
}

void Army::addElephant(Elephant elephant)
{
    ve.push_back(std::move(elephant));
}

void Army::printArmyInfo() const
{
    std::cout << _armyName << ": " << std::endl;
    printInfoForUnints(vi);
    printInfoForUnints(va);
    printInfoForUnints(vh);
    printInfoForUnints(vc);
    printInfoForUnints(ve);
}

std::string Army::armyName() const
{
    return _armyName;
}
