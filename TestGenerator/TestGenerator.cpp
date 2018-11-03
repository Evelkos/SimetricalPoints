#include "TestGenerator.hpp"
#include "../Point2D/Point2D.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

std::string to_string(int value) {
    std::ostringstream os;
    os <<value;
    return os.str();
}

std::string createTestname(int testNumber) {
    std::string name = "test" + to_string(testNumber) + ".txt";
    return name;
}

int TestGenerator::lastTestID = 0;

TestGenerator::TestGenerator()
{ }

TestGenerator::~TestGenerator()
{ }

void TestGenerator::createTestUnit(int numberOfPoints) {
    std::fstream testFile;
    testFile.open(createTestname(++lastTestID) , std::ios::out);
   // testFile << numberOfPoints << '\n';
    getPoints(testFile, numberOfPoints);
    testFile.close();
}

void TestGenerator::getPoints(std::fstream &testFile, int numberOfPoints) {
    Point2D point;
    for (int i = 0 ; i < numberOfPoints ; i++) {
        point.setRandomXY();
        testFile << point.getX() << ' ' << point.getY() << '\n';
    }
}

void TestGenerator::generateTests(int numberOfTests, int pointsPerTest) {
    for (int i = 0 ; i < numberOfTests ; i++)
        createTestUnit(pointsPerTest);
}
