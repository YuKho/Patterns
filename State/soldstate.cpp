#include "soldstate.h"
#include "gumballmachine.h"
#include <iostream>

void SoldState::insertQuarter()
{
    puts("Please wait, we're already giving you a gumball");
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

void SoldState::refill() {}

std::ostream &SoldState::print(std::ostream &os) const
{
    return os << "dispensing a gumball";
}
