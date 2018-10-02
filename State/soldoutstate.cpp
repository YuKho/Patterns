#include "soldoutstate.h"
#include "gumballmachine.h"
#include <iostream>

void SoldOutState::insertQuarter()
{
    puts("You can't insert a quarter, the machine is sold out");
}

void SoldOutState::ejectQuarter()
{
    puts("You can't eject, you haven't inserted a quarter yet");
}

void SoldOutState::turnCrank()
{
    puts("You turned, but there are no gumballs");
}

void SoldOutState::dispense()
{
    puts("No gumball dispensed");
}

void SoldOutState::refill()
{
    _gumballMachine->setState(_gumballMachine->getState(GumballMachine::StateType::NoQuarter));
}

std::ostream &SoldOutState::print(std::ostream &os) const
{
    return os << "dispensing a gumball";
}
