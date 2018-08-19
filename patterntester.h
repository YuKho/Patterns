#ifndef PATTERNTESTER_H
#define PATTERNTESTER_H

#include <string>

enum class Pattern { Strategy, Observer };

class PatternTester
{
public:
    static void testPattern(Pattern pattern);

private:
    static void testStrategy();
    static void testObserver();

    static void prinPreInfo(Pattern pattern);
    static void prinPostInfo(Pattern pattern);
    static std::string decorateMessage(std::string message);
    static std::string patternName(Pattern pattern);
};

#endif // PATTERNTESTER_H
