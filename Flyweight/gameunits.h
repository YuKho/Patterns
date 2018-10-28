#ifndef GAMEUNITS_H
#define GAMEUNITS_H

#include <string>
#include <memory>

class Image;

namespace Flyweight
{

class Unit
{
public:
    Unit(std::string name, int health);

protected:
    std::string _name;
    float _health;
    std::shared_ptr<Image> _picture;
};

class Goblin : public Unit
{
public:
    Goblin();
};

class Dragon : public Unit
{
public:
    Dragon();
};

}

#endif // GAMEUNITS_H
