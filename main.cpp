#include "patterntester.h"
#include <iostream>

int main()
{
    PatternTester::testPattern(Pattern::Strategy);
    PatternTester::testPattern(Pattern::Observer);

    std::cout << std::endl;
    std::cout << "All tests were finished.";
    std::cout << std::endl;
}
