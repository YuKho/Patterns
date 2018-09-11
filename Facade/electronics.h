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

#endif // ELECTRONICS_H
