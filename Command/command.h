#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() {}
};

#endif // COMMAND_H
