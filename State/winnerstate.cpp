#include "winnerstate.h"
#include "gumballmachine.h"
#include <iostream>

void WinnerState::insertQuarter()
{
    puts("Please wait, we're already giving you a Gumball");
}

void WinnerState::ejectQuarter()
{
    puts("Sorry, you already turned the crank");
}

void WinnerState::turnCrank()
{
    puts("Turning again doesn't get you another gumball!");
}

void WinnerState::dispense()
{
    const bool success = _gumballMachine->releaseBalls(2);
    success ? puts("YOU'RE A WINNER! You have been got two gumballs for your quarter")
            : puts("Oops, out of gumballs!");

    const GumballMachine::StateType nextState = success && !_gumballMachine->isEmpty()
            ? GumballMachine::StateType::NoQuarter
            : GumballMachine::StateType::SoldOut;

    _gumballMachine->setState(_gumballMachine->getState(nextState));
}

std::ostream &WinnerState::print(std::ostream &os) const
{
    return os << "despensing two gumballs for your quarter, because YOU'RE A WINNER!";
}
