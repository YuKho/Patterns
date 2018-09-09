#include "commands.h"
#include "devices.h"
#include <utility>

void EmptyCommand::execute()
{
}

LightCommand::LightCommand(std::shared_ptr<Light> light) : _light(std::move(light))
{
}

void LightCommand::undo()
{
    _light->dim(_level);
}

void LightOnCommand::execute()
{
    _level = _light->getLevel();
    _light->on();
}

void LightOffCommand::execute()
{
    _level = _light->getLevel();
    _light->off();
}

GarageDoorUpCommand::GarageDoorUpCommand(std::shared_ptr<GarageDoor> garageDoor)
    : _garageDoor(std::move(garageDoor))
{
}

void GarageDoorUpCommand::execute()
{
    _garageDoor->up();
}

GarageDoorDownCommand::GarageDoorDownCommand(std::shared_ptr<GarageDoor> garageDoor)
    : _garageDoor(std::move(garageDoor))
{
}

void GarageDoorDownCommand::execute()
{
    _garageDoor->up();
}

CeilingFanCommand::CeilingFanCommand(std::shared_ptr<CeilingFan> ceilingFan)
    : _ceilingFan(std::move(ceilingFan))
{
}

void CeilingFanCommand::undo()
{
    const auto level = static_cast<CeilingFan::Level>(_prevSpeed);
    switch (level)
    {
    case CeilingFan::Level::OFF:
        _ceilingFan->off();
        break;

    case CeilingFan::Level::LOW:
        _ceilingFan->low();
        break;

    case CeilingFan::Level::MEDIUM:
        _ceilingFan->medium();
        break;

    case CeilingFan::Level::HIGH:
        _ceilingFan->high();
        break;
    }
}

void CeilingFanHighCommand::execute()
{
    _prevSpeed = static_cast<int>(_ceilingFan->getSpeed());
    _ceilingFan->high();
}

void CeilingFanMediumCommand::execute()
{
     _prevSpeed = static_cast<int>(_ceilingFan->getSpeed());
    _ceilingFan->medium();
}

void CeilingFanLowCommand::execute()
{
    _prevSpeed = static_cast<int>(_ceilingFan->getSpeed());
   _ceilingFan->low();
}

void CeilingFanOffCommand::execute()
{
    _prevSpeed = static_cast<int>(_ceilingFan->getSpeed());
   _ceilingFan->off();
}

StereoOnWithCDCommand::StereoOnWithCDCommand(std::shared_ptr<Stereo> stereo)
    : _stereo(std::move(stereo))
{
}

void StereoOnWithCDCommand::execute()
{
    _stereo->on();
    _stereo->setCD();
    _stereo->setVolume(11);
}

StereoOffCommand::StereoOffCommand(std::shared_ptr<Stereo> stereo)
    : _stereo(std::move(stereo))
{
}

void StereoOffCommand::execute()
{
    _stereo->off();
}

TVOffCommand::TVOffCommand(std::shared_ptr<Tv> tv) : _tv(std::move(tv))
{
}

void TVOffCommand::execute()
{
    _tv->off();
}

void TVOffCommand::undo()
{
    _tv->on();
}

TVOnCommand::TVOnCommand(std::shared_ptr<Tv> tv) : _tv(std::move(tv))
{
}

void TVOnCommand::execute()
{
    _tv->on();
}

void TVOnCommand::undo()
{
    _tv->off();
}

HottubOnCommand::HottubOnCommand(std::shared_ptr<Hottub> hottub) : _hottub(std::move(hottub))
{
}

void HottubOnCommand::execute()
{
    _hottub->on();
    _hottub->setTemperature(104);
    _hottub->circulate();
}

void HottubOnCommand::undo()
{
    _hottub->off();
}


HottubOffCommand::HottubOffCommand(std::shared_ptr<Hottub> hottub) : _hottub(std::move(hottub))
{
}

void HottubOffCommand::execute()
{
    _hottub->setTemperature(98);
    _hottub->off();
}

void HottubOffCommand::undo()
{
    _hottub->on();
}
