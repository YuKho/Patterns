#ifndef PATTERNTESTER_H
#define PATTERNTESTER_H

#include <string>

enum class Pattern { Strategy, Observer, Decorator, Factory, Singleton, Command, Adapter, Facade,
                     TemplateMethod, Iterator };

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

    static void prinPreInfo(Pattern pattern);
    static void prinPostInfo(Pattern pattern);
    static std::string decorateMessage(std::string message, char decorChar = '#');
    static std::string patternName(Pattern pattern);
};

#endif // PATTERNTESTER_H
