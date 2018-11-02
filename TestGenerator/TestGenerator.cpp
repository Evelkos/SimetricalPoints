#include "TestGenerator.hpp"
#include "../Point2D/Point2D.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

TestGenerator::TestGenerator()
{ }

TestGenerator::~TestGenerator()
{ }

std::string to_string(int value) {
    std::ostringstream os;
    os <<value;
    return os.str();
}

std::string createTestname(int testNumber) {
    std::string name = "test" + to_string(testNumber) + ".txt";
    return name;
}

void TestGenerator::generateTest(int testNumber, int numberOfPoints) {
    std::fstream testFile;
    testFile.open(createTestname(testNumber), std::ios::out);
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
