#ifndef WEATHEROBSERVERS_H
#define WEATHEROBSERVERS_H

#include <memory>
#include <type_traits>

class Observable;
struct WeatherData;

class WeatherObserver
{
public:
    virtual void update(const WeatherData &data) = 0;
    virtual ~WeatherObserver() = default;
};

class DisplayElement
{
public:
    virtual void display() = 0;
    virtual ~DisplayElement() = default;
};

///////////////////////////////////////////////////////////////////////////////////////////////////

class BaseObserver : public WeatherObserver
{
public:
    explicit BaseObserver(std::weak_ptr<Observable> observable);
    void registerObservable(std::weak_ptr<Observable> observable);

    template <typename Observer>
    static std::shared_ptr<Observer> create(std::weak_ptr<Observable> observable)
    {
        static_assert (std::is_base_of<WeatherObserver, Observer>::value,
                       "Observer must be inherited from WeatherObserver");

        auto observer = std::make_shared<Observer>(std::move(observable));
        observer->registerObservable();
        return observer;
    }

private:
    void registerObservable();
    virtual std::shared_ptr<WeatherObserver> make_shared_from_this() = 0;

private:
    std::weak_ptr<Observable> _weatherStation;
};

class CurrentConditionsDisplay
        : public BaseObserver
        , public DisplayElement
        , public std::enable_shared_from_this<CurrentConditionsDisplay>
{
public:
    using BaseObserver::BaseObserver;

    void update(const WeatherData &data) override;
    void display() override;

private:
    std::shared_ptr<WeatherObserver> make_shared_from_this() override;

private:
    float _temperature = 80.0;
    float _humidity = 60.0;
    float _pressure = 30.0;
};

class StatisticsDisplay
        : public BaseObserver
        , public DisplayElement
        , public std::enable_shared_from_this<StatisticsDisplay>
{
public:
    using BaseObserver::BaseObserver;

    void update(const WeatherData &data) override;
    void display() override;

private:
    std::shared_ptr<WeatherObserver> make_shared_from_this() override;

private:
    float maxTemp = 0.0f;
    float minTemp = 200;
    float tempSum = 0.0f;
    int numReadings = 0;
};

class ForecastDisplay
        : public BaseObserver
        , public DisplayElement
        , public std::enable_shared_from_this<ForecastDisplay>
{
public:
    using BaseObserver::BaseObserver;

    void update(const WeatherData &data) override;
    void display() override;

private:
    std::shared_ptr<WeatherObserver> make_shared_from_this() override;

private:
    float currentPressure = 29.92f;
    float lastPressure = 0.0f;
};

#endif // WEATHEROBSERVERS_H
