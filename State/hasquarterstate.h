#ifndef HASQUARTERSTATE_H
#define HASQUARTERSTATE_H

#include "state.h"

class HasQuarterState : public State
{
public:
    using State::State;

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
    void refill() override;

    std::ostream &print(std::ostream &os) const override;
};

#endif // HASQUARTERSTATE_H
