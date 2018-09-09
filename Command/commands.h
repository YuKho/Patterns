#ifndef COMMANDS_H
#define COMMANDS_H

#include "command.h"
#include <memory>

class Light;
class GarageDoor;
class CeilingFan;
class Stereo;

class EmptyCommand : public Command
{
public:
    void execute() override;
};

class LightCommand : public Command
{
public:
    explicit LightCommand(std::shared_ptr<Light> light);
    void undo() override;

protected:
    std::shared_ptr<Light> _light;
    int _level = 0;
};

class LightOnCommand : public LightCommand
{
public:
    using LightCommand::LightCommand;

    void execute() override;
};

class LightOffCommand : public LightCommand
{
public:
    using LightCommand::LightCommand;

    void execute() override;
};

class GarageDoorUpCommand : public Command
{
public:
    explicit GarageDoorUpCommand(std::shared_ptr<GarageDoor> garageDoor);
    void execute() override;

private:
    std::shared_ptr<GarageDoor> _garageDoor;
};

class GarageDoorDownCommand : public Command
{
public:
    explicit GarageDoorDownCommand(std::shared_ptr<GarageDoor> garageDoor);
    void execute() override;

private:
    std::shared_ptr<GarageDoor> _garageDoor;
};

class CeilingFanCommand : public Command
{
public:
    explicit CeilingFanCommand(std::shared_ptr<CeilingFan> ceilingFan);
    void undo() override;

protected:
    std::shared_ptr<CeilingFan> _ceilingFan;
    int _prevSpeed = 0;
};

class CeilingFanHighCommand : public CeilingFanCommand
{
public:
    using CeilingFanCommand::CeilingFanCommand;

    void execute() override;
};

class CeilingFanMediumCommand : public CeilingFanCommand
{
public:
    using CeilingFanCommand::CeilingFanCommand;

    void execute() override;
};

class CeilingFanLowCommand : public CeilingFanCommand
{
public:
    using CeilingFanCommand::CeilingFanCommand;

    void execute() override;
};

class CeilingFanOffCommand : public CeilingFanCommand
{
public:
    using CeilingFanCommand::CeilingFanCommand;

    void execute() override;
};

class StereoOnWithCDCommand : public Command
{
public:
    explicit StereoOnWithCDCommand(std::shared_ptr<Stereo> stereo);
    void execute() override;

private:
    std::shared_ptr<Stereo> _stereo;
};

class StereoOffCommand : public Command
{
public:
    explicit StereoOffCommand(std::shared_ptr<Stereo> stereo);
    void execute() override;

private:
    std::shared_ptr<Stereo> _stereo;
};

#endif // COMMANDS_H
