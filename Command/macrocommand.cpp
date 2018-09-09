#include "macrocommand.h"
#include <utility>
#include <algorithm>
#include <iterator>

MacroCommand::MacroCommand(std::vector<std::shared_ptr<Command>> commands)
    : _commands(std::move(commands))
{
}

void MacroCommand::execute()
{
    for (const auto &command : _commands)
        command->execute();
}

void MacroCommand::undo()
{
    std::for_each(_commands.rbegin(), _commands.rend(), [](auto &command)
    { command->undo(); });
}
