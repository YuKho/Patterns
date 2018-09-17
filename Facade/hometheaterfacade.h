#ifndef HOMETHEATERFACADE_H
#define HOMETHEATERFACADE_H

#include <memory>
#include <string>

class Amplifier;
class Tuner;
class DvdPlayer;
class CdPlayer;
class Projector;
class TheaterLights;
class Screen;
class PopcornPopper;

class HomeTheaterFacade final
{
public:
    HomeTheaterFacade(std::shared_ptr<Amplifier> amp,
                      std::shared_ptr<Tuner> tuner,
                      std::shared_ptr<DvdPlayer> dvd,
                      std::shared_ptr<CdPlayer> cd,
                      std::shared_ptr<Projector> projector,
                      std::shared_ptr<TheaterLights> lights,
                      std::shared_ptr<Screen> screen,
                      std::shared_ptr<PopcornPopper> popper);

    void watchMovie(const std::string &movie) const;
    void endMovie() const;

    static std::unique_ptr<HomeTheaterFacade> createFacade();

private:
    std::shared_ptr<Amplifier> _amp;
    std::shared_ptr<Tuner> _tuner;
    std::shared_ptr<DvdPlayer> _dvd;
    std::shared_ptr<CdPlayer> _cd;
    std::shared_ptr<Projector> _projector;
    std::shared_ptr<TheaterLights> _lights;
    std::shared_ptr<Screen> _screen;
    std::shared_ptr<PopcornPopper> _popper;
};

#endif // HOMETHEATERFACADE_H
