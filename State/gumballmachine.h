#ifndef GUMBALLMACHINE_H
#define GUMBALLMACHINE_H

#include <memory>
#include <iosfwd>
#include <cstddef>

class State;

class GumballMachine final
{
public:
    enum class StateType { NoQuarter, HasQuarter, Sold, SoldOut, Winner };

public:
    explicit GumballMachine(size_t numberGumballs);

    void insertQuarter() const;
    void ejectQuarter() const;
    void turnCrank() const;
    void releaseBall();

    void setState(std::shared_ptr<State> state);
    std::shared_ptr<State> getState(StateType state);
    std::shared_ptr<State> getCurrentState() const;

    size_t getCount() const;
    std::ostream &print(std::ostream &os) const;

private:
    void refill(size_t count);

private:
    std::shared_ptr<State> _soldOutState;
    std::shared_ptr<State> _noQuarterState;
    std::shared_ptr<State> _hasQuarterState;
    std::shared_ptr<State> _soldState;
    std::shared_ptr<State> _winnerState;

    std::shared_ptr<State> _state;
    size_t _count = 0;
};

std::ostream &operator << (std::ostream &os, const GumballMachine &machine);

#endif // GUMBALLMACHINE_H
