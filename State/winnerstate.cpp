#include "winnerstate.h"
#include "gumballmachine.h"
#include <iostream>

void WinnerState::insertQuarter()
{
    puts("Please wait, we're already giving you a Gumball");
}

void WinnerState::ejectQuarter()
{
    puts("Please wait, we're already giving you a Gumball");
}

void WinnerState::turnCrank()
{
    puts("Turning again doesn't get you another gumball!");
}

void WinnerState::dispense()
{
    _gumballMachine->releaseBall();
    if (_gumballMachine->getCount() == 0)
    {
        _gumballMachine->setState(_gumballMachine->getState(GumballMachine::StateType::SoldOut));
    }
    else
    {
        _gumballMachine->releaseBall();
        puts("YOU'RE A WINNER! You got two gumballs for your quarter");
        if (_gumballMachine->getCount() > 0)
        {
            _gumballMachine->setState(_gumballMachine->getState(GumballMachine::StateType::NoQuarter));
        }
        else
        {
            puts("Oops, out of gumballs!");
            _gumballMachine->setState(_gumballMachine->getState(GumballMachine::StateType::SoldOut));
        }
    }
}

void WinnerState::refill() {}

std::ostream &WinnerState::print(std::ostream &os) const
{
    return os << "despensing two gumballs for your quarter, because YOU'RE A WINNER!";
}
