#include "noquarterstate.h"
#include "gumballmachine.h"
#include <iostream>

void NoQuarterState::insertQuarter()
{
    puts("You inserted a quarter");
    _gumballMachine->setState(_gumballMachine->getState(GumballMachine::StateType::HasQuarter));
}

void NoQuarterState::ejectQuarter()
{
    puts("You haven't inserted a quarter");
}

void NoQuarterState::turnCrank()
{
    puts("You turned, but there's no quarter");
}

void NoQuarterState::dispense()
{
    puts("You need to pay first");
}

void NoQuarterState::refill() { }

std::ostream &NoQuarterState::print(std::ostream &os) const
{
    return os << "waiting for quarter";
}
