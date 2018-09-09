#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "command.h"
#include <vector>
#include <memory>

class MacroCommand : public Command
{
public:
    explicit MacroCommand(std::vector<std::shared_ptr<Command>> commands);

    virtual void execute() override;
    virtual void undo() override;

private:
    std::vector<std::shared_ptr<Command>> _commands;
};

#endif // MACROCOMMAND_H
