#ifndef WEATHEROBSERVERS_H
#define WEATHEROBSERVERS_H

#include <memory>

class Observable;
struct WeatherData;

class  WeatherObserver
{
public:
    virtual void update(std::shared_ptr<Observable> observable, const WeatherData &data) = 0;
    virtual ~WeatherObserver() = default;
};

class DisplayElement
{
public:
    virtual void display() = 0;
    virtual ~DisplayElement() = default;
};

class CurrentConditionsDisplay
        : public std::enable_shared_from_this<CurrentConditionsDisplay>
        , public WeatherObserver
        , public DisplayElement
{
public:
    explicit CurrentConditionsDisplay(std::weak_ptr<Observable> observable);
    void registerObservable(std::weak_ptr<Observable> observable);
    void registerObservable();

    void update(std::shared_ptr<Observable> observable, const WeatherData &data) override;
    void display() override;

    static std::shared_ptr<CurrentConditionsDisplay> create(std::weak_ptr<Observable> observable);

private:
    float _temperature = 80.0;
    float _humidity = 60.0;
    float _pressure = 30.0;
    std::weak_ptr<Observable> _weatherStation;
};

#endif // WEATHEROBSERVERS_H
