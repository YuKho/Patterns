#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include <string>
#include <memory>

class Tuner;
class DvdPlayer;
class CdPlayer;

class Amplifier final
{
public:
    explicit Amplifier(std::string description);
    void on() const;
    void off() const;
    void setStereoSound() const;
    void setSurroundSound() const;
    void setVolume(int level) const;
    void setTuner(std::shared_ptr<Tuner> tuner);
    void setDvd(std::shared_ptr<DvdPlayer> dvd);
    void setCd(std::shared_ptr<CdPlayer> cd);
    std::string toString() const;

private:
    std::string _description;
    std::shared_ptr<Tuner> _tuner;
    std::shared_ptr<DvdPlayer> _dvd;
    std::shared_ptr<CdPlayer> _cd;
};

class CdPlayer final
{
public:
    CdPlayer(std::string description, std::shared_ptr<Amplifier> amplifier);
    void on() const;
    void off() const;
    void eject();
    void play(std::string title);
    void play(int track);
    void stop();
    void pause() const;
    std::string toString() const;

private:
    std::string _description;
    int _currentTrack = 0;
    std::shared_ptr<Amplifier> _amplifier;
    std::string _title;
};

class DvdPlayer final
{
public:
    DvdPlayer(std::string description, std::shared_ptr<Amplifier> amplifier);
    void on() const;
    void off() const;
    void eject();
    void play(std::string movie);
    void play(int track);
    void stop();
    void pause() const;
    void setTwoChannelAudio() const;
    void setSurroundAudio() const;
    std::string toString() const;

private:
    std::string _description;
    int _currentTrack = 0;
    std::shared_ptr<Amplifier> _amplifier;
    std::string _movie;
};

class PopcornPopper
{
public:
    explicit PopcornPopper(std::string description);
    void on() const;
    void off() const;
    void pop() const;
    std::string toString() const;

private:
    std::string _description;
};

class Projector
{
public:
    Projector(std::string description, std::shared_ptr<DvdPlayer> dvdPlayer);
    void on() const;
    void off() const;
    void wideScreenMode() const;
    void tvMode() const;
    std::string toString() const;

private:
     std::string _description;
     std::shared_ptr<DvdPlayer> _dvdPlayer;
};

class Screen
{
public:
    explicit Screen(std::string description);
    void up() const;
    void down() const;
    std::string toString() const;

private:
    std::string _description;
};

class TheaterLights
{
public:
    explicit TheaterLights(std::string description);
    void on() const;
    void off() const;
    void dim(int level) const;
    std::string toString() const;

private:
    std::string _description;
};

class Tuner
{
public:
    Tuner(std::string description, std::shared_ptr<Amplifier> amplifier);
    void on() const;
    void off() const;
    void setFrequency(double frequency);
    void setAm() const;
    void setFm() const;
    std::string toString() const;

private:
    std::string _description;
    std::shared_ptr<Amplifier> _amplifier;
    double _frequency = 0;
};

#endif // ELECTRONICS_H
