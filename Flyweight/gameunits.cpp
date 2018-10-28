#include "gameunits.h"
#include "unitimagesfactory.h"
#include <utility>

Flyweight::Unit::Unit(std::string name, int health)
    : _name(std::move(name)), _health(health)
{
}

Flyweight::Goblin::Goblin() : Unit("Goblin", 8)
{
    _picture = UnitImagesFactory::create_goblin_image();
}

Flyweight::Dragon::Dragon() : Unit("Dragon", 800)
{
    _picture = UnitImagesFactory::create_dragon_image();
}
