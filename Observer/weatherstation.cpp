#include "weatherstation.h"
#include "weatherobservers.h"
#include <algorithm>
#include <utility>
#include <cmath>
#include <tuple>

void WeatherStation::measurementsChanged()
{
    notifyObservers();
}

bool WeatherStation::needToNotify(float temp) const
{
    return std::abs(temp - _data.temperature) >= 0.5f;
}

void WeatherStation::registerObserver(std::shared_ptr<WeatherObserver> observer)
{
    _observers.push_back(std::move(observer));
}

void WeatherStation::removeObserver(const std::shared_ptr<WeatherObserver> &observer)
{
    const auto it = std::find(_observers.cbegin(), _observers.cend(), observer);
    if (it != _observers.cend())
        _observers.erase(it);
}

void WeatherStation::notifyObservers()
{
    for (const auto &observer : _observers)
        observer->update(shared_from_this(), _data);
}

void WeatherStation::setMeasurements(float temp, float hum, float press)
{
    const float tempBefore = _data.temperature;
    std::tie(_data.temperature, _data.humidity, _data.pressure) =
            std::tie(temp, hum, press);

    if (needToNotify(tempBefore))
        measurementsChanged();
}
