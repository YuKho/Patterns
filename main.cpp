#include "patterntester.h"
#include <iostream>

int main()
{
    PatternTester::testPattern(Pattern::Strategy);
    PatternTester::testPattern(Pattern::Observer);
    PatternTester::testPattern(Pattern::Decorator);
    PatternTester::testPattern(Pattern::Factory);
    PatternTester::testPattern(Pattern::Singleton);
    PatternTester::testPattern(Pattern::Command);
    PatternTester::testPattern(Pattern::Adapter);
    PatternTester::testPattern(Pattern::Facade);
    PatternTester::testPattern(Pattern::TemplateMethod);
    PatternTester::testPattern(Pattern::Iterator);

    std::cout << "All tests were finished." << std::endl;
}
