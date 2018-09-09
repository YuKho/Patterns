#include "devices.h"
#include <iostream>
#include <utility>

Location::Location(std::string location) : _location(std::move(location))
{
}

void Light::on()
{
    _level = 100;
    std::cout << _location << " light is on" << std::endl;;
}

void Light::off()
{
    _level = 0;
    std::cout << _location << " light is off" << std::endl;
}

void Light::dim(int level)
{
    if (level == 0)
        off();
    else if (level == 100)
        on();
    else
    {
        _level = level;
        std::cout << "Light is dimmed to " << level << "%" << std::endl;
    }
}

int Light::getLevel() const
{
    return _level;
}

void GarageDoor::up()
{
    std::cout << _location << " garage Door is Up" << std::endl;
}

void GarageDoor::down()
{
    std::cout << _location << " garage Door is Down" << std::endl;
}

void GarageDoor::stop()
{
    std::cout << _location << " garage Door is Stopped" << std::endl;
}

void GarageDoor::lightOn()
{
    std::cout << _location << " garage light is on" << std::endl;
}

void GarageDoor::lightOff()
{
    std::cout << _location << " garage light is off" << std::endl;
}

void CeilingFan::high()
{
    // turns the ceiling fan on to high
    _level = Level::HIGH;
    std::cout << _location << " ceiling fan is on high" << std::endl;
}

void CeilingFan::medium()
{
    // turns the ceiling fan on to medium
    _level = Level::MEDIUM;
    std::cout << _location << " ceiling fan is on medium" << std::endl;
}

void CeilingFan::low()
{
    // turns the ceiling fan on to low
    _level = Level::LOW;
    std::cout << _location << " ceiling fan is on low" << std::endl;
}

void CeilingFan::off()
{
    // turns the ceiling fan off
    _level = Level::OFF;
    std::cout << _location << " ceiling fan is off" << std::endl;
}

CeilingFan::Level CeilingFan::getSpeed()
{
    return _level;
}

void Stereo::on()
{
    std::cout << _location << " stereo is on" << std::endl;
}

void Stereo::off()
{
    std::cout << _location << " stereo is off" << std::endl;
}

void Stereo::setCD()
{
    std::cout << _location << " stereo is set for CD input" << std::endl;
}

void Stereo::setDVD()
{
    std::cout << _location << " stereo is set for DVD input" << std::endl;
}

void Stereo::setRadio()
{
    std::cout << _location << " stereo is set for Radio" << std::endl;
}

void Stereo::setVolume(int volume)
{
    // code to set the volume
    // valid range: 1-11 (after all 11 is better than 10, right?)
    std::cout << _location << " Stereo volume set to " << volume << std::endl;
}
