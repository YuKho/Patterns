#include "hometheaterfacade.h"
#include "electronics.h"
#include <utility>
#include <iostream>

HomeTheaterFacade::HomeTheaterFacade(std::shared_ptr<Amplifier> amp,
                                     std::shared_ptr<Tuner> tuner,
                                     std::shared_ptr<DvdPlayer> dvd,
                                     std::shared_ptr<CdPlayer> cd,
                                     std::shared_ptr<Projector> projector,
                                     std::shared_ptr<TheaterLights> lights,
                                     std::shared_ptr<Screen> screen,
                                     std::shared_ptr<PopcornPopper> popper)
    : _amp(std::move(amp)),
      _tuner(std::move(tuner)),
      _dvd(std::move(dvd)),
      _cd(std::move(cd)),
      _projector(std::move(projector)),
      _lights(std::move(lights)),
      _screen(std::move(screen)),
      _popper(std::move(popper))
{
}

void HomeTheaterFacade::watchMovie(const std::string &movie) const
{
    std::cout << "Get ready to watch a movie..." << std::endl;
    _popper->on();
    _popper->pop();
    _lights->dim(10);
    _screen->down();
    _projector->on();
    _projector->wideScreenMode();
    _amp->on();
    _amp->setDvd(_dvd);
    _amp->setSurroundSound();
    _amp->setVolume(5);
    _dvd->on();
    _dvd->play(movie);
}

void HomeTheaterFacade::endMovie() const
{
    std::cout << "Shutting movie theater down..." << std::endl;
    _popper->off();
    _lights->on();
    _screen->up();
    _projector->off();
    _amp->off();
    _dvd->stop();
    _dvd->eject();
    _dvd->off();
}

std::unique_ptr<HomeTheaterFacade> HomeTheaterFacade::createFacade()
{
    auto amp = std::make_shared<Amplifier>("Top-O-Line Amplifier");
    auto tuner = std::make_shared<Tuner>("Top-O-Line AM/FM Tuner", amp);
    auto dvd = std::make_shared<DvdPlayer>("Top-O-Line DVD Player", amp);
    auto cd = std::make_shared<CdPlayer>("Top-O-Line CD Player", amp);
    auto projector = std::make_shared<Projector>("Top-O-Line Projector", dvd);
    auto lights = std::make_shared<TheaterLights>("Theater Ceiling Lights");
    auto screen = std::make_shared<Screen>("Theater Screen");
    auto popper = std::make_shared<PopcornPopper>("Popcorn Popper");

    return std::make_unique<HomeTheaterFacade>(std::move(amp), std::move(tuner), std::move(dvd),
                                               std::move(cd), std::move(projector),
                                               std::move(lights), std::move(screen),
                                               std::move(popper));
}
