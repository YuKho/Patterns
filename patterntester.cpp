#include "patterntester.h"

#include "Strategy/duck.h"
#include "Strategy/behaviors.h"

#include "Observer/weatherstation.h"
#include "Observer/weatherobservers.h"

#include "Decorator/beverage.h"

#include "Factory/SimpleFactory/simplepizzastore.h"
#include "Factory/chicagopizzastore.h"
#include "Factory/nypizzastore.h"

#include "Singleton/singelton.h"

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

    case Pattern::Singleton:
        testSingleton();
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
    std::cout << decorateMessage("Simple Factory", '-') << std::endl;
    std::vector<std::unique_ptr<SimplePizza>> pizzas;
    pizzas.push_back(SimplePizzaStore::orderPizza("cheese"));
    pizzas.push_back(SimplePizzaStore::orderPizza("veggie"));
    std::cout << "\nWe ordered: \n\n";
    for (const auto &pizza : pizzas)
        std::cout << pizza.get() << std::endl;
    std::cout << decorateMessage("Simple Factory end", '-') << std::endl << std::endl;

    std::cout << decorateMessage("Abstract Factory", '-') << std::endl;
    auto nyStore = std::make_shared<NYPizzaStore>();
    auto chicagoStore = std::make_shared<ChicagoPizzaStore>();

    std::shared_ptr<Pizza> pizza = nyStore->orderPizza("cheese");
    std::cout << "Ethan ordered a \'" + pizza->name() + "\'\n\n";

    pizza = chicagoStore->orderPizza("cheese");
    std::cout << "Joel ordered a \'" + pizza->name() + "\'\n\n";

    pizza = nyStore->orderPizza("clam");
    std::cout << "Ethan ordered a \'" + pizza->name() + "\'\n\n";

    pizza = chicagoStore->orderPizza("clam");
    std::cout << "Joel ordered a \'" + pizza->name() + "\'\n\n";

    pizza = nyStore->orderPizza("pepperoni");
    std::cout << "Ethan ordered a \'" + pizza->name() + "\'\n\n";

    pizza = chicagoStore->orderPizza("pepperoni");
    std::cout << "Joel ordered a \'" + pizza->name() + "\'\n\n";

    pizza = nyStore->orderPizza("veggie");
    std::cout << "Ethan ordered a \'" + pizza->name() + "\'\n";
    std::cout << pizza.get() << "\n";

    pizza = chicagoStore->orderPizza("veggie");
    std::cout << "Joel ordered a \'" + pizza->name() + "\'\n";
    std::cout << pizza.get() << std::endl;
    std::cout << decorateMessage("Abstract Factory end", '-') << std::endl << std::endl;
}

void PatternTester::testSingleton()
{
    const Singleton &singleton1 = Singleton::instance();
    const Singleton &singleton2 = Singleton::instance();
//    const Singleton singleton3 = Singleton::instance(); // not allowed
//    const Singleton singleton4 = std::move(Singleton::instance()); // not allowed

    std::cout << "&singleton1: [" << &singleton1 << "] == &singleton2: [" << &singleton2 << "]"
              << std::endl;
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

std::string PatternTester::decorateMessage(std::string message, char decorChar)
{
    message.insert(0, " ");
    message.push_back(' ');
    const size_t maxLength = 100;
    const size_t messageLength = message.size();
    const size_t decorSideLength = maxLength > messageLength ? (maxLength - messageLength) / 2 : 0;
    const std::string decorStr(decorSideLength, decorChar);
    message.insert(0, decorStr);
    message += decorStr;

    if (message.size() < maxLength)
        message.push_back(decorChar);

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

    case Pattern::Singleton:
        return "Singlton";
    }

    return "No name";
}
