#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include "command.h"

#include <array>
#include <memory>
#include <cassert>
#include <iostream>

template <size_t Count>
class RemoteControl
{
public:
    RemoteControl();

    void setCommand(size_t slot, const std::shared_ptr<Command> &onCommand,
                    const std::shared_ptr<Command> &offCommand);
    void onButtonWasPushed(size_t slot);
    void offButtonWasPushed(size_t slot);

private:
     void init();

private:
    std::array<std::shared_ptr<Command>, Count> _onCommands;
    std::array<std::shared_ptr<Command>, Count> _offCommands;
};

template <size_t Count>
RemoteControl<Count>::RemoteControl()
{
    init();
}

template <size_t Count>
void RemoteControl<Count>::setCommand(size_t slot, const std::shared_ptr<Command> &onCommand,
                               const std::shared_ptr<Command> &offCommand)
{
    assert(slot < Count);
    _onCommands[slot] = onCommand;
    _offCommands[slot] = offCommand;
}

template <size_t Count>
void RemoteControl<Count>::onButtonWasPushed(size_t slot)
{
    assert(slot < Count);
    _onCommands[slot]->execute();
}

template <size_t Count>
void RemoteControl<Count>::offButtonWasPushed(size_t slot)
{
    assert(slot < Count);
    _offCommands[slot]->execute();
}

template <size_t Count>
void RemoteControl<Count>::init()
{

}

template <size_t Count>
std::ostream & operator << (std::ostream &os, const RemoteControl<Count> &remote)
{
    return os;
}

#endif // REMOTECONTROL_H
