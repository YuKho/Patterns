#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <memory>

class Army;
class ArmyBuilder;

class Director
{
public:
    ~Director();
    void createInternalArmy(ArmyBuilder &builder);
    void printArmy() const;

    static std::unique_ptr<Army> createExternalArmy(ArmyBuilder &builder);

private:
    static void createArmy(ArmyBuilder &builder);

private:
    std::unique_ptr<Army> _army;
};

#endif // DIRECTOR_H
