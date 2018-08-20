#include "weatherobservers.h"
#include "weatherstation.h"
#include <iostream>
#include <tuple>
#include <cmath>

BaseObserver::BaseObserver(std::weak_ptr<Observable> observable)
    : _weatherStation(std::move(observable))
{
}

void BaseObserver::registerObservable(std::weak_ptr<Observable> observable)
{
    if (!_weatherStation.expired())
        _weatherStation.lock()->removeObserver(make_shared_from_this());

    _weatherStation = std::move(observable);
    registerObservable();
}

void BaseObserver::registerObservable()
{
    if (!_weatherStation.expired())
        _weatherStation.lock()->registerObserver(make_shared_from_this());
}

void CurrentConditionsDisplay::update(const WeatherData &data)
{
    std::tie(_temperature, _humidity, _pressure) = std::tie(data.temperature, data.humidity,
                                                            data.pressure);
    display();
}

void CurrentConditionsDisplay::display()
{
    std::cout << "Current conditions display:\n";
    std::cout << "\tTemp:     " << _temperature << "\n";
    std::cout << "\tHumidity: " << _humidity << "\n";
    std::cout << "\tPressure: " << _pressure << "\n";
}

std::shared_ptr<WeatherObserver> CurrentConditionsDisplay::make_shared_from_this()
{
    return shared_from_this();
}

void StatisticsDisplay::update(const WeatherData &data)
{
    tempSum += data.temperature;
    ++numReadings;

    if (data.temperature > maxTemp)
        maxTemp = data.temperature;

    if (data.temperature < minTemp)
        minTemp = data.temperature;

    display();
}

void StatisticsDisplay::display()
{
    std::cout << "Statistics display:\n";
    std::cout << "\tAvg/Max/Min temperature = " << (tempSum / numReadings)
              << "/" << maxTemp << "/" << minTemp << "\n";
}

std::shared_ptr<WeatherObserver> StatisticsDisplay::make_shared_from_this()
{
    return shared_from_this();
}

void ForecastDisplay::update(const WeatherData &data)
{
    lastPressure = currentPressure;
    currentPressure = data.pressure;

    display();
}

void ForecastDisplay::display()
{
    std::cout << "Forecast display: \n";
    if (currentPressure > lastPressure)
        std::cout << "\tImproving weather on the way!\n";

    else if ((currentPressure - lastPressure) < std::fabs(0.01f))
        std::cout << "\tMore of the same\n";

    else if (currentPressure < lastPressure)
        std::cout << "\tWatch out for cooler, rainy weather\n";
}

std::shared_ptr<WeatherObserver> ForecastDisplay::make_shared_from_this()
{
    return shared_from_this();
}
