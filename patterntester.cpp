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

#include "Command/remotecontrol.h"
#include "Command/devices.h"
#include "Command/commands.h"
#include "Command/macrocommand.h"

#include "Adapter/ducks.h"
#include "Adapter/turkeys.h"
#include "Adapter/adapters.h"

#include "Facade/hometheaterfacade.h"

#include "TemplateMethod/beverages.h"

#include "Iterator/waitress.h"
#include "Iterator/dinermenu.h"
#include "Iterator/pancakehousemenu.h"

#include "Composite/menucomponent.h"
#include "Composite/compositewaitress.h"

#include "State/gumballmachine.h"

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

    case Pattern::Command:
        testCommand();
        break;

    case Pattern::Adapter:
        testAdapter();
        break;

    case Pattern::Facade:
        testFacade();
        break;

    case Pattern::TemplateMethod:
        testTemplateMethod();
        break;

    case Pattern::Iterator:
        testIterator();
        break;

    case Pattern::Composite:
        testComposite();
        break;

    case Pattern::State:
        testState();
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
    StaticSingleton &staticSingleton = StaticSingleton::instance();
    auto &dynamicSingleton = DynamicSingleton::instance();

    staticSingleton.setData("Data changed");
    dynamicSingleton->setData("Data changed");

//    not allowed operations:
//    StaticSingleton ss; // calling a private constructor of class 'StaticSingleton'
//    DynamicSingleton ds; // calling a private constructor of class 'DynamicSingleton'
//    StaticSingleton ss(staticSingleton); // use of deleted function
//    DynamicSingleton ds(*dynamicSingleton); // use of deleted function


    StaticSingleton &staticSingleton2 = StaticSingleton::instance();
    auto &dynamicSingleton2 = DynamicSingleton::instance();

    std::cout << "&staticSingleton address: [" << &staticSingleton
              << "] == &staticSingleton2 address: [" << &staticSingleton2 << "]"
              << std::endl;

    std::cout << "&dynamicSingleton address: [" << &dynamicSingleton
              << "] == &dynamicSingleton2 address: [" << &dynamicSingleton2 << "]\n"
              << std::endl;

    std::cout << "staticSingleton2 data: " << staticSingleton2.data() << std::endl;
    std::cout << "dynamicSingleton2 data: " << dynamicSingleton2->data() << std::endl;

    DynamicSingleton::resetInstance(); // all references and pointers for 'DynamicSingleton' now
                                       // are invalid.

//    dynamicSingleton->data(); // Undefined Behaviour !!!

    auto &dynamicSingleton3 = DynamicSingleton::instance();
    std::cout << "dynamicSingleton3 has default data: " << dynamicSingleton3->data() << std::endl;
}

void PatternTester::testCommand()
{
    auto remoteControl = std::make_unique<RemoteControl<8>>();

    auto livingRoomLight = std::make_shared<Light>("Living Room");
    auto tv = std::make_shared<Tv>("Living Room");
    auto kitchenLight = std::make_shared<Light>("Kitchen");
    auto ceilingFan= std::make_shared<CeilingFan>("Living Room");
    auto garageDoor = std::make_shared<GarageDoor>("House");
    auto stereo = std::make_shared<Stereo>("Living Room");
    auto hottub = std::make_shared<Hottub>("Bath Room");

    auto livingRoomLightOn = std::make_shared<LightOnCommand>(livingRoomLight);
    auto livingRoomLightOff = std::make_shared<LightOffCommand>(livingRoomLight);
    auto kitchenLightOn = std::make_shared<LightOnCommand>(kitchenLight);
    auto kitchenLightOff = std::make_shared<LightOffCommand>(kitchenLight);

    auto ceilingFanHigh = std::make_shared<CeilingFanHighCommand>(ceilingFan);
    auto ceilingFanMedium = std::make_shared<CeilingFanMediumCommand>(ceilingFan);
    auto ceilingFanLow = std::make_shared<CeilingFanLowCommand>(ceilingFan);
    auto ceilingFanOff = std::make_shared<CeilingFanOffCommand>(ceilingFan);

    auto garageDoorUp = std::make_shared<GarageDoorUpCommand>(garageDoor);
    auto garageDoorDown = std::make_shared<GarageDoorDownCommand>(garageDoor);

    auto stereoOnWithCD = std::make_shared<StereoOnWithCDCommand>(stereo);
    auto stereoOff = std::make_shared<StereoOffCommand>(stereo);

    auto tvOn = std::make_shared<TVOnCommand>(tv);
    auto tvOff = std::make_shared<TVOffCommand>(tv);
    auto hottubOn = std::make_shared<HottubOnCommand>(hottub);
    auto hottubOff = std::make_shared<HottubOffCommand>(hottub);

    std::vector<std::shared_ptr<Command>> partyOn {livingRoomLightOn, stereoOnWithCD,
                                                   tvOn, hottubOn};
    std::vector<std::shared_ptr<Command>> partyOff {livingRoomLightOff, stereoOff,
                                                   tvOff, hottubOff};
    auto partyOnMacro = std::make_shared<MacroCommand>(std::move(partyOn));
    auto partyOffMacro = std::make_shared<MacroCommand>(std::move(partyOff));

    remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);
    remoteControl->setCommand(1, kitchenLightOn, kitchenLightOff);

    remoteControl->setCommand(2, ceilingFanHigh, ceilingFanOff);
    remoteControl->setCommand(3, ceilingFanMedium, ceilingFanOff);
    remoteControl->setCommand(4, ceilingFanLow, ceilingFanOff);
    remoteControl->setCommand(5, ceilingFanOff, ceilingFanOff);

    remoteControl->setCommand(6, stereoOnWithCD, stereoOff);

    remoteControl->setCommand(7, partyOnMacro, partyOffMacro);

    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    remoteControl->undoButtonWasPushed();
    remoteControl->offButtonWasPushed(0);
    remoteControl->onButtonWasPushed(0);
    remoteControl->undoButtonWasPushed();

    remoteControl->onButtonWasPushed(2);
    remoteControl->offButtonWasPushed(2);
    remoteControl->undoButtonWasPushed();
    remoteControl->offButtonWasPushed(2);
    remoteControl->onButtonWasPushed(3);
    remoteControl->onButtonWasPushed(4);
    remoteControl->undoButtonWasPushed();

    std::cout << "--- Pushing Macro On---" << std::endl;
    remoteControl->onButtonWasPushed(7);
    std::cout << "--- Pushing Macro Off---" << std::endl;
    remoteControl->offButtonWasPushed(7);
}

void PatternTester::testAdapter()
{
    const auto testDuck = [](AbstractDuck *duck)
    {
        duck->quack();
        duck->fly();
    };

    auto duck = std::make_shared<WildDuck>();
    auto turkey = std::make_shared<WildTurkey>();

    auto turkeyObjectAdapter = std::make_shared<TurkeyObjectAdapter>(turkey);
    auto turkeyClassAdapter = std::make_shared<TurkeyClassAdapter>();

    std::cout << "The Turkey says..." << std::endl;
    turkey->gobble();
    turkey->fly();

    std::cout << "\nThe Duck says..." << std::endl;
    testDuck(duck.get());

    std::cout << "\nThe TurkeyObjectAdapter says..." << std::endl;
    testDuck(turkeyObjectAdapter.get());

    std::cout << "\nThe TurkeyClassAdapter says..." << std::endl;
    testDuck(turkeyClassAdapter.get());
}

void PatternTester::testFacade()
{
    auto homeTheater = HomeTheaterFacade::createFacade();
    homeTheater->watchMovie("Raiders of the Lost Ark");
    std::cout << std::endl;
    homeTheater->endMovie();
}

void PatternTester::testTemplateMethod()
{
    auto tea = std::make_unique<Tea>();
    auto coffee = std::make_unique<Coffee>();

    std::cout << "Making tea..." << std::endl;
    tea->prepareRecipe();

    std::cout << "\nMaking coffee..." << std::endl;
    coffee->prepareRecipe();
}

void PatternTester::testIterator()
{
    std::initializer_list<std::shared_ptr<Menu>> list = {std::make_shared<DinerMenu>(),
                                                         std::make_shared<PancakeHouseMenu>()};

    auto waitress = std::make_unique<Waitress>(list);

    waitress->printMenu();
    std::cout << std::endl;

    waitress->printVegetarianMenu();
    std::cout << std::endl;
}

void PatternTester::testComposite()
{
    auto waitress = std::make_unique<Composite::Waitress>(Composite::Waitress::createMenu());
    waitress->printMenu();

    if (auto menu = waitress->getMenu(0))
    {
        std::cout << "\nThe first menu is: \n";
        menu->print();
    }

    if (auto menu = waitress->getMenu(waitress->menuCount() - 1))
    {
        std::cout << "\nThe last menu is: \n";
        menu->print();
    }

    if (auto menu = waitress->getMenu(waitress->menuCount() - 1))
    {
        waitress->removeMenu(menu);
        std::cout << "\nLast menu removed.\n";
        waitress->printMenu();
    }
}

void PatternTester::testState()
{
    const auto gumballMachine = std::make_unique<GumballMachine>(10);
    std::cout << *gumballMachine << std::endl;

    testGumballMachine(gumballMachine.get());
    testGumballMachine(gumballMachine.get());
    testGumballMachine(gumballMachine.get());
    testGumballMachine(gumballMachine.get());
    testGumballMachine(gumballMachine.get());

    if (gumballMachine->getCount() == 0)
        gumballMachine->refill(10);

    testGumballMachine(gumballMachine.get());
}

void PatternTester::prinPreInfo(Pattern pattern)
{
    std::string message{patternName(pattern) + " pattern test start:"};
    std::cout << decorateMessage(message) << std::endl;
}

void PatternTester::prinPostInfo(Pattern pattern)
{
    std::string message{patternName(pattern) + " pattern test finished"};
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
        return "Singleton";

    case Pattern::Command:
        return "Command";

    case Pattern::Adapter:
        return "Adapter";

    case Pattern::Facade:
        return "Facade";

    case Pattern::TemplateMethod:
        return "TemplateMethod";

    case Pattern::Iterator:
        return "Iterator";

    case Pattern::Composite:
        return "Composite";

    case Pattern::State:
        return "State";
    }

    return "No name";
}

void PatternTester::testGumballMachine(const GumballMachine * const gumballMachine)
{
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    std::cout << *gumballMachine << std::endl;
}
