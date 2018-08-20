#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H

#include <memory>
#include <vector>

class WeatherObserver;

class Observable
{
public:
    virtual void registerObserver(std::shared_ptr<WeatherObserver> observer) = 0;
    virtual void removeObserver(const std::shared_ptr<WeatherObserver> &observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Observable() = default;
};

struct WeatherData
{
    float temperature, humidity, pressure;
};

class WeatherStation : public Observable
{
public:
    void registerObserver(std::shared_ptr<WeatherObserver> observer) override;
    void removeObserver(const std::shared_ptr<WeatherObserver> &observer) override;
    void notifyObservers() override;

    void setMeasurements(float temp, float hum, float press);

private:
    void measurementsChanged();
    bool needToNotify(float temp) const;

private:
    std::vector<std::shared_ptr<WeatherObserver>> _observers;
    WeatherData _data;
};

#endif // WEATHERSTATION_H
