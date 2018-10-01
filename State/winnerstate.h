#ifndef WINNERSTATE_H
#define WINNERSTATE_H

#include "state.h"

class WinnerState : public State
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

#endif // WINNERSTATE_H
