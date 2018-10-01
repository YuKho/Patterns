#ifndef SOLDOUTSTATE_H
#define SOLDOUTSTATE_H

#include "state.h"

class SoldOutState : public State
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

#endif // SOLDOUTSTATE_H
