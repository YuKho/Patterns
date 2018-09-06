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
    void execute() const override;
};

class LightOnCommand : public Command
{
public:
    explicit LightOnCommand(std::shared_ptr<Light> light);
    void execute() const override;

private:
    std::shared_ptr<Light> _light;
};

class LightOffCommand : public Command
{
public:
    explicit LightOffCommand(std::shared_ptr<Light> light);
    void execute() const override;

private:
    std::shared_ptr<Light> _light;
};

class GarageDoorUpCommand : public Command
{
public:
    explicit GarageDoorUpCommand(std::shared_ptr<GarageDoor> garageDoor);
    void execute() const override;

private:
    std::shared_ptr<GarageDoor> _garageDoor;
};

class GarageDoorDownCommand : public Command
{
public:
    explicit GarageDoorDownCommand(std::shared_ptr<GarageDoor> garageDoor);
    void execute() const override;

private:
    std::shared_ptr<GarageDoor> _garageDoor;
};

class CeilingFanOnCommand : public Command
{
public:
    explicit CeilingFanOnCommand(std::shared_ptr<CeilingFan> ceilingFan);
    void execute() const override;

private:
    std::shared_ptr<CeilingFan> _ceilingFan;
};

class CeilingFanOffCommand : public Command
{
public:
    explicit CeilingFanOffCommand(std::shared_ptr<CeilingFan> ceilingFan);
    void execute() const override;

private:
    std::shared_ptr<CeilingFan> _ceilingFan;
};

class StereoOnWithCDCommand : public Command
{
public:
    explicit StereoOnWithCDCommand(std::shared_ptr<Stereo> stereo);
    void execute() const override;

private:
    std::shared_ptr<Stereo> _stereo;
};

class StereoOffCommand : public Command
{
public:
    explicit StereoOffCommand(std::shared_ptr<Stereo> stereo);
    void execute() const override;

private:
    std::shared_ptr<Stereo> _stereo;
};

#endif // COMMANDS_H
