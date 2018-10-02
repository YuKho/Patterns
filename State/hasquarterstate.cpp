#include "hasquarterstate.h"
#include "gumballmachine.h"
#include <iostream>
#include <random>

void HasQuarterState::insertQuarter()
{
    puts("You can't insert another quarter");
}

void HasQuarterState::ejectQuarter()
{
    puts("Quarter returned");
    _gumballMachine->setState(_gumballMachine->getState(GumballMachine::StateType::NoQuarter));
}

void HasQuarterState::turnCrank()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 10);

    puts("You turned...");
    const int winner = dis(gen);
    if (winner == 0 && _gumballMachine->getCount() > 1)
        _gumballMachine->setState(_gumballMachine->getState(GumballMachine::StateType::Winner));
    else
        _gumballMachine->setState(_gumballMachine->getState(GumballMachine::StateType::Sold));
}

void HasQuarterState::dispense()
{
    puts("No gumball dispensed");
}

std::ostream &HasQuarterState::print(std::ostream &os) const
{
    return os << "waiting for turn of crank";
}
