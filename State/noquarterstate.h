#ifndef NOQUARTERSTATE_H
#define NOQUARTERSTATE_H

#include "state.h"

class NoQuarterState : public State
{
public:
    using State::State;

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;

    std::ostream &print(std::ostream &os) const override;
};

#endif // NOQUARTERSTATE_H
