#include "weatherobservers.h"
#include "weatherstation.h"
#include <iostream>
#include <tuple>

CurrentConditionsDisplay::CurrentConditionsDisplay(const std::shared_ptr<Observable> &observable)
    : _weatherStation(observable)
{
}

void CurrentConditionsDisplay::registerObservable(const std::shared_ptr<Observable> &observable)
{
    _weatherStation = observable;
}

void CurrentConditionsDisplay::update(const std::shared_ptr<Observable> &observable,
                                      const WeatherData &data)
{
    if (observable == _weatherStation.lock())
    {
        std::cout << "Observable data changed:\n";
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
    std::cout << "Temp:     " << _temperature << "\n";
    std::cout << "Humidity: " << _humidity << "\n";
    std::cout << "Pressure: " << _pressure << "\n";
}
