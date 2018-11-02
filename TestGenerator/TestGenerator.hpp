#include <iostream>
#include <fstream>
#include <sstream>

#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H

class TestGenerator
{
    public:
        TestGenerator();
        ~TestGenerator();
        void generateTest(int testNumber, int numberOfPoints);
        void getPoints(std::fstream &testFile, int numberOfPoints);
};

#endif // TESTGENERATOR_H
