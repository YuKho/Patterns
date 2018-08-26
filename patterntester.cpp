#include "patterntester.h"
#include "Strategy/duck.h"
#include "Strategy/behaviors.h"
#include "Observer/weatherstation.h"
#include "Observer/weatherobservers.h"
#include "Decorator/beverage.h"
#include "Factory/SimpleFactory/simplepizzastore.h"
#include "Factory/SimpleFactory/simplepizzafactory.h"
#include "Factory/chicagopizzastore.h"
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

    case Pattern::Decorator:
        testDecorator();
        break;

    case Pattern::Factory:
        testFactory();
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
    BaseObserver::create<CurrentConditionsDisplay>(station);
    BaseObserver::create<StatisticsDisplay>(station);
    BaseObserver::create<ForecastDisplay>(station);

    station->setMeasurements(80.f, 65.f, 30.4f);
    station->setMeasurements(82.f, 70.f, 29.2f);
    station->setMeasurements(78.f, 90.f, 29.2f);
    station->setMeasurements(78.2f, 90.f, 29.2f); // <-- probably will not be notified
}

void PatternTester::testDecorator()
{
    auto espresso = std::make_shared<Espresso>();
    std::cout << espresso.get() << std::endl;

    auto darkRoast = std::make_shared<DarkRoast>();
    auto darkRoastMocha = std::make_shared<Mocha>(std::move(darkRoast));
    auto darkRoastMochaMocha = std::make_shared<Mocha>(std::move(darkRoastMocha));
    auto darkRoastMochaMochaWhip = std::make_shared<Whip>(std::move(darkRoastMochaMocha));
    std::cout << darkRoastMochaMochaWhip.get() << std::endl;

    auto houseBlend = std::make_shared<HouseBlend>();
    auto houseBlendSoy = std::make_shared<Soy>(std::move(houseBlend));
    auto houseBlendSoyMocha = std::make_shared<Mocha>(std::move(houseBlendSoy));
    auto houseBlendSoyMochaWhip = std::make_shared<Whip>(std::move(houseBlendSoyMocha));
    std::cout << houseBlendSoyMochaWhip.get() << std::endl;
}

void PatternTester::testFactory()
{
    std::cout << "\n-------------------------Simple Factory--------------------------" << std::endl;
    const std::unique_ptr<Pizza> pizzaCheese = SimplePizzaStore::orderPizza("cheese");
    std::cout << "Pizza prepared.\n" << std::endl;
    std::cout << "We ordered a " << pizzaCheese.get() << std::endl << std::endl;

    const std::unique_ptr<Pizza> pizzaVegie = SimplePizzaStore::orderPizza("veggie");
    std::cout << "Pizza prepared.\n" << std::endl;
    std::cout << "We ordered a " << pizzaVegie.get();
    std::cout << "------------------------Simple Factory end-----------------------" << std::endl;

    std::cout << "\n-------------------------Abstact Factory--------------------------" << std::endl;
    const std::unique_ptr<PizzaStore> chicagoStore = std::make_unique<ChicagoPizzaStore>();
    chicagoStore->orderPizza("cheese");
    std::cout << "\n----------------------Abstact Factory end-------------------------" << std::endl;
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

    case Pattern::Decorator:
        return "Decorator";

    case Pattern::Factory:
        return "Factory";
    }

    return "No name";
}
