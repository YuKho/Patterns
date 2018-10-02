#include "state.h"

std::ostream &operator <<(std::ostream &os, const State &state)
{
    return state.print(os);
}

State::State(GumballMachine *gumballMachine) : _gumballMachine(gumballMachine)
{
}

void State::refill()
{
}
