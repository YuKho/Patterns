#include "armybuilder.h"
#include "army.h"
#include <utility>

ArmyBuilder::~ArmyBuilder() = default;

void ArmyBuilder::createArmy()
{
    _army = std::make_unique<Army>("No Name");
}

std::unique_ptr<Army> ArmyBuilder::getArmy()
{
    return std::move(_army);
}

void RomanArmyBuilder::createArmy()
{
    _army = std::make_unique<Army>("Roman army");
}

void RomanArmyBuilder::buildInfantryman() const { _army->addInfantryman(Infantryman(1)); }

void RomanArmyBuilder::buildArcher() const { _army->addArcher(Archer(3)); }

void RomanArmyBuilder::buildHorseman() const { _army->addHorseman(Horseman(5)); }

void RomanArmyBuilder::buildCatapult() const { _army->addCatapult(Catapult(8)); }

void CarthaginianArmyBuilder::createArmy()
{
    _army = std::make_unique<Army>("Carthaginian army");
}

void CarthaginianArmyBuilder::buildInfantryman() const { _army->addInfantryman(Infantryman(2)); }

void CarthaginianArmyBuilder::buildArcher() const { _army->addArcher(Archer(6)); }

void CarthaginianArmyBuilder::buildHorseman() const { _army->addHorseman(Horseman(8)); }

void CarthaginianArmyBuilder::buildElephant() const { _army->addCatapult(Catapult(10)); }
