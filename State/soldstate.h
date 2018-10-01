#ifndef SOLDSTATE_H
#define SOLDSTATE_H

#include "state.h"

class SoldState : public State
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

#endif // SOLDSTATE_H
