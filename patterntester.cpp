#include "patterntester.h"
#include <iostream>
#include <iomanip>

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

}

void PatternTester::testObserver()
{

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
