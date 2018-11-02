#include <iostream>
#include <fstream>
#include <sstream>

#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H

class TestGenerator
{
    private:
    static int lastTestID;

    public:
        TestGenerator();
        ~TestGenerator();
        void generateTests(int numberOfTests, int pointsPerTest);

    private:
        void createTestUnit(int numberOfPoints);
        void getPoints(std::fstream &testFile, int numberOfPoints);
};

#endif // TESTGENERATOR_H
