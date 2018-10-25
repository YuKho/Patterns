#ifndef ARMYBUILDER_H
#define ARMYBUILDER_H

#include <memory>

class Army;

class ArmyBuilder
{
public:
    virtual ~ArmyBuilder();

    virtual void createArmy();
    virtual std::unique_ptr<Army> getArmy();

    virtual void buildInfantryman() const {}
    virtual void buildArcher() const {}
    virtual void buildHorseman() const {}
    virtual void buildCatapult() const {}
    virtual void buildElephant() const {}

protected:
    std::unique_ptr<Army> _army;
};

class RomanArmyBuilder: public ArmyBuilder
{
public:
    void createArmy() override;
    void buildInfantryman() const override;
    void buildArcher() const override;
    void buildHorseman() const override;
    void buildCatapult() const override;
};

class CarthaginianArmyBuilder: public ArmyBuilder
{
public:
    void createArmy() override;
    void buildInfantryman() const override;
    void buildArcher() const override;
    void buildHorseman() const override;
    void buildElephant() const override;
};

#endif // ARMYBUILDER_H
