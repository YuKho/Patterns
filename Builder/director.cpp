#include "director.h"
#include "army.h"
#include "armybuilder.h"

Director::~Director() = default;

void Director::createInternalArmy(ArmyBuilder &builder)
{
    createArmy(builder);
    _army = builder.getArmy();
}

void Director::printArmy() const
{
    _army->printArmyInfo();
}

std::unique_ptr<Army> Director::createExternalArmy(ArmyBuilder &builder)
{
    createArmy(builder);
    return builder.getArmy();
}

void Director::createArmy(ArmyBuilder &builder)
{
    builder.createArmy();
    builder.buildInfantryman();
    builder.buildArcher();
    builder.buildHorseman();
    builder.buildCatapult();
    builder.buildElephant();
}
