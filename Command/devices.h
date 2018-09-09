#ifndef DEVICES_H
#define DEVICES_H

#include <string>

class Location
{
public:
    virtual ~Location() = default;
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
    void dim(int level);
    int getLevel() const;

private:
    int _level;
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
    enum class Level { OFF, LOW, MEDIUM, HIGH };

public:
    using Location::Location;

    void high();
    void medium();
    void low();
    void off();
    Level getSpeed();

private:
    Level _level;
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
