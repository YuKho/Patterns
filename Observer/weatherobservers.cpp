#include "weatherobservers.h"
#include "weatherstation.h"
#include <iostream>
#include <tuple>

CurrentConditionsDisplay::CurrentConditionsDisplay(std::weak_ptr<Observable> observable)
    : _weatherStation(std::move(observable))
{
}

void CurrentConditionsDisplay::registerObservable(std::weak_ptr<Observable> observable)
{
    if (!_weatherStation.expired())
        _weatherStation.lock()->removeObserver(shared_from_this());

    _weatherStation = std::move(observable);
    if (!_weatherStation.expired())
        _weatherStation.lock()->registerObserver(shared_from_this());
}

void CurrentConditionsDisplay::registerObservable()
{
    if (!_weatherStation.expired())
        _weatherStation.lock()->registerObserver(shared_from_this());
}


void CurrentConditionsDisplay::update(std::shared_ptr<Observable> observable,
                                      const WeatherData &data)
{
    if (observable == _weatherStation.lock())
    {
        std::tie(_temperature, _humidity, _pressure) =
                std::tie(data.temperature, data.humidity, data.pressure);
        display();
    }
    else
    {
        std::cerr << "Wrong observable object." << std::endl;
    }
}

void CurrentConditionsDisplay::display()
{
    std::cout << "CurrentConditionsDisplay:\n";
    std::cout << "Temp:     " << _temperature << "\n";
    std::cout << "Humidity: " << _humidity << "\n";
    std::cout << "Pressure: " << _pressure << "\n";
}

std::shared_ptr<CurrentConditionsDisplay> CurrentConditionsDisplay::create(
        std::weak_ptr<Observable> observable)
{
    auto observer = std::make_shared<CurrentConditionsDisplay>(observable);
    observer->registerObservable();
    return observer;
}
