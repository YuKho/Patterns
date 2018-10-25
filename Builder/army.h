#ifndef ARMY_H
#define ARMY_H

#include "units.h"
#include <vector>
#include <string>

class Army
{
public:
    explicit Army(std::string name);
    ~Army();

    void addInfantryman(Infantryman infantryman);
    void addArcher(Archer archer);
    void addHorseman(Horseman horseman);
    void addCatapult(Catapult catapult);
    void addElephant(Elephant elephant);

    void printArmyInfo() const;
    std::string armyName() const;

private:

    template <typename T>
    static void printInfoForUnints(const std::vector<T> &units)
    {
        for (const auto unit : units)
            unit.info();
    }

private:
    std::vector<Infantryman> vi;
    std::vector<Archer>      va;
    std::vector<Horseman>    vh;
    std::vector<Catapult>    vc;
    std::vector<Elephant>    ve;

    std::string _armyName;
};

#endif // ARMY_H
