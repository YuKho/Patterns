#include "commands.h"
#include "devices.h"
#include <utility>

void EmptyCommand::execute() const
{
}

LightOnCommand::LightOnCommand(std::shared_ptr<Light> light) : _light(std::move(light))
{
}

void LightOnCommand::execute() const
{
    _light->on();
}

LightOffCommand::LightOffCommand(std::shared_ptr<Light> light) : _light(std::move(light))
{
}

void LightOffCommand::execute() const
{
    _light->off();
}

GarageDoorUpCommand::GarageDoorUpCommand(std::shared_ptr<GarageDoor> garageDoor)
    : _garageDoor(std::move(garageDoor))
{
}

void GarageDoorUpCommand::execute() const
{
    _garageDoor->up();
}

GarageDoorDownCommand::GarageDoorDownCommand(std::shared_ptr<GarageDoor> garageDoor)
    : _garageDoor(std::move(garageDoor))
{
}

void GarageDoorDownCommand::execute() const
{
    _garageDoor->up();
}

CeilingFanOnCommand::CeilingFanOnCommand(std::shared_ptr<CeilingFan> ceilingFan)
    : _ceilingFan(std::move(ceilingFan))
{
}

void CeilingFanOnCommand::execute() const
{
    _ceilingFan->high();
}

CeilingFanOffCommand::CeilingFanOffCommand(std::shared_ptr<CeilingFan> ceilingFan)
    : _ceilingFan(std::move(ceilingFan)){
}

void CeilingFanOffCommand::execute() const
{
    _ceilingFan->off();
}

StereoOnWithCDCommand::StereoOnWithCDCommand(std::shared_ptr<Stereo> stereo)
    : _stereo(std::move(stereo))
{
}

void StereoOnWithCDCommand::execute() const
{
    _stereo->on();
    _stereo->setCD();
    _stereo->setVolume(11);
}

StereoOffCommand::StereoOffCommand(std::shared_ptr<Stereo> stereo)
    : _stereo(std::move(stereo))
{
}

void StereoOffCommand::execute() const
{
    _stereo->off();
}
