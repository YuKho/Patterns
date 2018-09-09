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

class Tv : private Location
{
public:
    using Location::Location;

    void on() const;
    void off() const;
    void setInputChannelForDvd();

private:
    int _channel = 1;
};

class Hottub : private Location
{
public:
    using Location::Location;

    void on();
    void off();
    void circulate() const;
    void jetsOn() const;
    void jetsOff() const;
    void setTemperature(int temperature);

private:
    bool _on {false};
    int _temperature = 18;
};

#endif // DEVICES_H
