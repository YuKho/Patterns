#include "electronics.h"
#include <utility>
#include <iostream>

Amplifier::Amplifier(std::string description)
    : _description(std::move(description))
{
}

void Amplifier::on() const
{
    std::cout << _description << " on" << std::endl;
}

void Amplifier::off() const
{
    std::cout << _description << " off" << std::endl;
}

void Amplifier::setStereoSound() const
{
    std::cout << _description << " stereo mode on" << std::endl;
}

void Amplifier::setSurroundSound() const
{
    std::cout << _description << " surround sound on (5 speakers, 1 subwoofer)" << std::endl;
}

void Amplifier::setVolume(int level) const
{
    std::cout << _description << " setting volume to " << level << std::endl;
}

void Amplifier::setTuner(std::shared_ptr<Tuner> tuner)
{
    std::cout << _description << " setting tuner to " + _dvd->toString() << std::endl;
    _tuner = std::move(tuner);
}

void Amplifier::setDvd(std::shared_ptr<DvdPlayer> dvd)
{
    std::cout << _description << " setting DVD player to " << dvd->toString() << std::endl;
    _dvd = std::move(dvd);
}

void Amplifier::setCd(std::shared_ptr<CdPlayer> cd)
{
    std::cout << _description << " setting CD player to " << cd->toString() << std::endl;
    _cd = std::move(cd);
}

std::string Amplifier::toString() const
{
    return _description;
}

CdPlayer::CdPlayer(std::string description, std::shared_ptr<Amplifier> amplifier)
    : _description(std::move(description)), _amplifier(std::move(amplifier))
{
}

void CdPlayer::on() const
{
    std::cout << _description << " on" << std::endl;
}

void CdPlayer::off() const
{
    std::cout << _description << " off" << std::endl;
}

void CdPlayer::eject()
{
    _title.clear();
    std::cout << _description << " eject" << std::endl;
}

void CdPlayer::play(std::string title)
{
    _title = std::move(title);
    _currentTrack = 0;
    std::cout << _description << " playing \"" + title + "\"" << std::endl;
}

void CdPlayer::play(int track)
{
    if (_title.empty())
    {
        std::cout << _description << " can't play track " << _currentTrack
                  << ", no cd inserted" << std::endl;
    }
    else
    {
        _currentTrack = track;
        std::cout << _description << " playing track " << _currentTrack << std::endl;
    }
}

void CdPlayer::stop()
{
    _currentTrack = 0;
    std::cout << _description << " stopped" << std::endl;
}

void CdPlayer::pause() const
{
    std::cout << _description << " paused \"" << _title << "\"" << std::endl;
}

std::string CdPlayer::toString() const
{
    return _description;
}

DvdPlayer::DvdPlayer(std::string description, std::shared_ptr<Amplifier> amplifier)
    : _description(std::move(description)), _amplifier(std::move(amplifier))
{
}

void DvdPlayer::on() const
{
    std::cout << _description << " on" << std::endl;
}

void DvdPlayer::off() const
{
    std::cout << _description << " off" << std::endl;
}

void DvdPlayer::eject()
{
    _movie.clear();
    std::cout << _description << " eject" << std::endl;
}

void DvdPlayer::play(std::string movie)
{
    _movie = std::move(movie);
    _currentTrack = 0;
    std::cout << _description << " playing \"" << movie << "\"" << std::endl;
}

void DvdPlayer::play(int track)
{
    if (_movie.empty())
    {
        std::cout << _description << " can't play track " << track
                  << " no dvd inserted" << std::endl;
    }
    else
    {
        _currentTrack = track;
        std::cout << _description << " playing track " << _currentTrack
                  << " of \"" + _movie + "\"" << std::endl;
    }
}

void DvdPlayer::stop()
{
    _currentTrack = 0;
    std::cout << _description << " stopped \"" << _movie << "\"" << std::endl;
}

void DvdPlayer::pause() const
{
    std::cout << _description << " paused \"" << _movie << "\"" << std::endl;
}

void DvdPlayer::setTwoChannelAudio() const
{
    std::cout << _description << " set two channel audio" << std::endl;
}

void DvdPlayer::setSurroundAudio() const
{
    std::cout << _description << " set surround audio" << std::endl;
}

std::string DvdPlayer::toString() const
{
    return _description;
}

PopcornPopper::PopcornPopper(std::string description) : _description(std::move(description))
{
}

void PopcornPopper::on() const
{
    std::cout << _description << " on" << std::endl;
}

void PopcornPopper::off() const
{
    std::cout << _description << " off" << std::endl;
}

void PopcornPopper::pop() const
{
    std::cout << _description << " popping popcorn!" << std::endl;
}

std::string PopcornPopper::toString() const
{
    return _description;
}

Projector::Projector(std::string description, std::shared_ptr<DvdPlayer> dvdPlayer)
    : _description(std::move(description)), _dvdPlayer(std::move(dvdPlayer))
{
}

void Projector::on() const
{
    std::cout << _description << " on" << std::endl;
}

void Projector::off() const
{
    std::cout << _description << " off" << std::endl;
}

void Projector::wideScreenMode() const
{
    std::cout << _description << " in widescreen mode (16x9 aspect ratio)" << std::endl;
}

void Projector::tvMode() const
{
    std::cout << _description << " in tv mode (4x3 aspect ratio)" << std::endl;
}

std::string Projector::toString() const
{
    return _description;
}

Screen::Screen(std::string description) : _description(std::move(description))
{
}

void Screen::up() const
{
    std::cout << _description << " going up" << std::endl;
}

void Screen::down() const
{
    std::cout << _description << " going down" << std::endl;
}

std::string Screen::toString() const
{
    return _description;
}

TheaterLights::TheaterLights(std::string description) : _description(std::move(description))
{
}

void TheaterLights::on() const
{
    std::cout << _description << " on" << std::endl;
}

void TheaterLights::off() const
{
    std::cout << _description << " off" << std::endl;
}

void TheaterLights::dim(int level) const
{
    std::cout << _description << " dimming to " << level  << "%" << std::endl;
}

std::string TheaterLights::toString() const
{
    return _description;
}

Tuner::Tuner(std::string description, std::shared_ptr<Amplifier> amplifier)
    : _description(std::move(description)), _amplifier(std::move(amplifier))
{
}

void Tuner::on() const
{
    std::cout << _description << " on" << std::endl;
}

void Tuner::off() const
{
    std::cout << _description << " off" << std::endl;
}

void Tuner::setFrequency(double frequency)
{
    std::cout << _description << " setting frequency to " << frequency << std::endl;
    _frequency = frequency;
}

void Tuner::setAm() const
{
    std::cout << _description << " setting AM mode" << std::endl;
}

void Tuner::setFm() const
{
    std::cout << _description << " setting FM mode" << std::endl;
}

std::string Tuner::toString() const
{
    return _description;
}
