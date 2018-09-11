#include "hometheaterfacade.h"
#include <utility>

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

std::unique_ptr<HomeTheaterFacade> HomeTheaterFacade::createFacade()
{
    return std::make_unique<HomeTheaterFacade>(); // TODO
}
