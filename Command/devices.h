#ifndef DEVICES_H
#define DEVICES_H

#include <string>

class Location
{
public:
    virtual ~Location() = default;

protected:
    explicit Location(std::string _location);

protected:
    std::string _location;
};

class Light : private Location
{
public:
    using Location::Location;

    void on();
    void off();
};

class GarageDoor : private Location
{
public:
    using Location::Location;

    void up();
    void down();
    void stop();
    void lightOn();
    void lightOff();
};

class CeilingFan : private Location
{
public:
    using Location::Location;

    void high();
    void medium();
    void low();
    void off();
    int getSpeed();

private:
    int level;
    static const int HIGH = 2;
    static const int MEDIUM = 1;
    static const int LOW = 0;
};

class Stereo : private Location
{
public:
    using Location::Location;

    void on();
    void off();
    void setCD();
    void setDVD();
    void setRadio();
    void setVolume(int volume);
};

#endif // DEVICES_H
