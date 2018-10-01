#include "gumballmachine.h"

#include "noquarterstate.h"
#include "hasquarterstate.h"
#include "soldstate.h"
#include "soldoutstate.h"
#include "winnerstate.h"

#include <utility>
#include <iostream>
#include <sstream>

GumballMachine::GumballMachine(size_t numberGumballs)
    : _soldOutState(new SoldOutState(this)),
      _noQuarterState(new NoQuarterState(this)),
      _hasQuarterState(new HasQuarterState(this)),
      _soldState(new SoldState(this)),
      _winnerState(new WinnerState(this)),
      _count(numberGumballs)
{
    if (numberGumballs > 0)
        _state = _noQuarterState;
}

void GumballMachine::insertQuarter() const
{
    _state->insertQuarter();
}

void GumballMachine::ejectQuarter() const
{
    _state->ejectQuarter();
}

void GumballMachine::turnCrank() const
{
    _state->turnCrank();
    _state->dispense();
}

void GumballMachine::setState(std::shared_ptr<State> state)
{
    _state = std::move(state);
}

void GumballMachine::releaseBall()
{
    puts("A gumball comes rolling out the slot...");
    if (_count != 0)
        --_count;
}

std::shared_ptr<State> GumballMachine::getState(GumballMachine::StateType state)
{
    switch (state)
    {
    case StateType::NoQuarter:
        return _noQuarterState;

    case StateType::HasQuarter:
        return _hasQuarterState;

    case StateType::Sold:
        return _soldState;

    case StateType::SoldOut:
        return _soldOutState;

    case StateType::Winner:
        return _winnerState;
    }

    return nullptr;
}

std::shared_ptr<State> GumballMachine::getCurrentState() const
{
    return _state;
}

size_t GumballMachine::getCount() const
{
    return _count;
}

void GumballMachine::refill(size_t count)
{
    _count += count;
    std::cout << "The gumball machine was just refilled; it's new count is: " << _count
              << std::endl;
    _state->refill();
}

std::ostream &GumballMachine::print(std::ostream &os) const
{
    std::string result;
    result.append("\nMighty Gumball, Inc.");
    result.append("\nStanding Gumball Model #2004");
    result.append("\nInventory: " + std::to_string(_count) + " gumball");
    if (_count != 1)
        result.append("s");

    result.append("\n");
    std::ostringstream oss;
    oss << *_state;
    result.append(std::string{"Machine is "} + oss.str() + "\n");
    return os << result;
}

std::ostream &operator <<(std::ostream &os, const GumballMachine &machine)
{
    return machine.print(os);
}
