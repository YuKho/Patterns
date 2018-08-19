#include "patterntester.h"
#include "Strategy/duck.h"
#include "Strategy/behaviors.h"
#include "Observer/weatherstation.h"
#include "Observer/weatherobservers.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

void PatternTester::testPattern(Pattern pattern)
{
    prinPreInfo(pattern);

    switch (pattern)
    {
    case Pattern::Strategy:
        testStrategy();
        break;

    case Pattern::Observer:
        testObserver();
        break;
    }

    prinPostInfo(pattern);
}

void PatternTester::testStrategy()
{
    std::vector<std::shared_ptr<Duck>> ducks;

    const auto mallarDuck = std::make_shared<MallardDuck>();
    const auto modelDuck = std::make_shared<ModelDuck>();
    const auto redheadDuck = std::make_shared<RedheadDuck>();
    const auto decoyDuck = std::make_shared<DecoyDuck>();
    decoyDuck->setFlyBehavior(std::make_shared<FlyRocketPowered>());

    ducks.push_back(mallarDuck);
    ducks.push_back(modelDuck);
    ducks.push_back(redheadDuck);
    ducks.push_back(decoyDuck);

    for (const auto &duck : ducks)
    {
        duck->display();
        duck->swim();
        duck->performFly();
        duck->performQuack();
        std::cout << std::endl;
    }
}

void PatternTester::testObserver()
{
    const auto station = std::make_shared<WeatherStation>();

    const auto display = std::make_shared<CurrentConditionsDisplay>(station);
    station->registerObserver(display);

    station->setMeasurements(80.f, 65.f, 30.4f);
    station->setMeasurements(82.f, 70.f, 29.2f);
    station->setMeasurements(78.f, 90.f, 29.2f);
    station->setMeasurements(78.2f, 90.f, 29.2f); // <-- probably will not be notified
}

void PatternTester::prinPreInfo(Pattern pattern)
{
    std::string message{patternName(pattern) + " pattern test start:"};
    std::cout << decorateMessage(message) << std::endl;
}

void PatternTester::prinPostInfo(Pattern pattern)
{
    std::string message{patternName(pattern) + " pattern test finished:"};
    std::cout << decorateMessage(message) << std::endl << std::endl;
}

std::string PatternTester::decorateMessage(std::string message)
{
    message.insert(0, " ");
    message.push_back(' ');
    const size_t maxLength = 100;
    const size_t messageLength = message.size();
    const size_t decorSideLength = maxLength > messageLength ? (maxLength - messageLength) / 2 : 0;
    const std::string decorStr(decorSideLength, '#');
    message.insert(0, decorStr);
    message += decorStr;

    if (message.size() < maxLength)
        message.push_back('#');

    return message;
}

std::string PatternTester::patternName(Pattern pattern)
{
    switch (pattern)
    {
    case Pattern::Strategy:
        return "Strategy";

    case Pattern::Observer:
        return "Observer";
    }
}
