#ifndef STATE_H
#define STATE_H

#include <iosfwd>

class GumballMachine;

class State
{
public:
    explicit State(GumballMachine *gumballMachine);
    virtual ~State() = default;
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
    virtual void refill() = 0;

    virtual std::ostream &print(std::ostream &) const = 0;

protected:
    GumballMachine *_gumballMachine;
};

std::ostream &operator << (std::ostream &os, const State &state);

#endif // STATE_H
