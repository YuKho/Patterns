#include "soldoutstate.h"
#include "gumballmachine.h"
#include <iostream>

void SoldOutState::insertQuarter()
{
    puts("Please wait, we're already giving you a gumball");
}

void SoldOutState::ejectQuarter()
{
    puts("Sorry, you already turned the crank");
}

void SoldOutState::turnCrank()
{
    puts("Turning twice doesn't get you another gumball!");
}

void SoldOutState::dispense()
{
    _gumballMachine->releaseBall();
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

void SoldOutState::refill() {}

std::ostream &SoldOutState::print(std::ostream &os) const
{
    return os << "dispensing a gumball";
}
