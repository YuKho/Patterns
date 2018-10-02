#include "soldstate.h"
#include "gumballmachine.h"
#include <iostream>

void SoldState::insertQuarter()
{
    puts("Please wait, we're already giving you a Gumball");
}

void SoldState::ejectQuarter()
{
    puts("Sorry, you already turned the crank");
}

void SoldState::turnCrank()
{
    puts("Turning twice doesn't get you another gumball!");
}

void SoldState::dispense()
{
    const bool success = _gumballMachine->releaseBalls(1);
    if (!success)
        puts("Oops, out of gumballs!");

    const GumballMachine::StateType nextState = success && !_gumballMachine->isEmpty()
            ? GumballMachine::StateType::NoQuarter
            : GumballMachine::StateType::SoldOut;

    _gumballMachine->setState(_gumballMachine->getState(nextState));
}

std::ostream &SoldState::print(std::ostream &os) const
{
    return os << "dispensing a gumball";
}
