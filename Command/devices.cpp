#include "devices.h"
#include <iostream>
#include <utility>

Location::Location(std::string location) : _location(std::move(location))
{
}

void Light::on()
{
    std::cout << _location << " light is on" << std::endl;;
}

void Light::off()
{
    std::cout << _location << " light is off" << std::endl;
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
    level = HIGH;
    std::cout << _location << " ceiling fan is on high" << std::endl;
}

void CeilingFan::medium()
{
    // turns the ceiling fan on to medium
    level = MEDIUM;
    std::cout << _location << " ceiling fan is on medium" << std::endl;
}

void CeilingFan::low()
{
    // turns the ceiling fan on to low
    level = LOW;
    std::cout << _location << " ceiling fan is on low" << std::endl;
}

void CeilingFan::off()
{
    // turns the ceiling fan off
    level = 0;
    std::cout << _location << " ceiling fan is off" << std::endl;
}

int CeilingFan::getSpeed()
{
    return level;
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
