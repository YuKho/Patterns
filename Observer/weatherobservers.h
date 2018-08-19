#ifndef WEATHEROBSERVERS_H
#define WEATHEROBSERVERS_H

#include <memory>

class Observable;
struct WeatherData;

class  WeatherObserver
{
public:
    virtual void update(const std::shared_ptr<Observable> &observable, const WeatherData &data) = 0;
    virtual ~WeatherObserver() = default;
};

class DisplayElement
{
public:
    virtual void display() = 0;
    virtual ~DisplayElement() = default;
};

class CurrentConditionsDisplay : public WeatherObserver, public DisplayElement
{
public:
    explicit CurrentConditionsDisplay(const std::shared_ptr<Observable> &observable = nullptr);
    void registerObservable(const std::shared_ptr<Observable> &observable);

    void update(const std::shared_ptr<Observable> &observable, const WeatherData &data) override;
    void display() override;

private:
    float _temperature = 0.0;
    float _humidity = 20.0;
    float _pressure = 80.0;
    std::weak_ptr<Observable> _weatherStation;
};

#endif // WEATHEROBSERVERS_H
