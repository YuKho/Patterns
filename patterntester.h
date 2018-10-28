#ifndef PATTERNTESTER_H
#define PATTERNTESTER_H

#include <string>

class GumballMachine;

enum class Pattern { Strategy, Observer, Decorator, Factory, Singleton, Command, Adapter, Facade,
                     TemplateMethod, Iterator, Composite, State, Bridge, Builder, Flyweight,
                     // Interpreter , Proxy, // TODO
                     ChainOfResponsibility, Mediator };

class PatternTester
{
public:
    static void testPattern(Pattern pattern);

private:
    static void testStrategy();
    static void testObserver();
    static void testDecorator();
    static void testFactory();
    static void testSingleton();
    static void testCommand();
    static void testAdapter();
    static void testFacade();
    static void testTemplateMethod();
    static void testIterator();
    static void testComposite();
    static void testState();
    static void testBridge();
    static void testBuilder();
    static void testFlyweight();
    static void testChainOfResponsibility();
    static void testMediator();

    static void prinPreInfo(Pattern pattern);
    static void prinPostInfo(Pattern pattern);
    static std::string decorateMessage(std::string message, char decorChar = '#');
    static std::string patternName(Pattern pattern);

    static void testGumballMachine(const GumballMachine *gumballMachine);
};

#endif // PATTERNTESTER_H
