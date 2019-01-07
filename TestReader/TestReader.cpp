#include "TestReader.hpp"
#include <iostream>

TestReader::TestReader()
{ }

TestReader::~TestReader()
{ }

std::vector<Point2D> TestReader::readTestFile(std::string testFileName) {
    std::vector<Point2D> testUnit;
    std::fstream testFile;
    testFile.open(testFileName, std::fstream::in);
    testUnit = loadPointsFromFile(testFile);
    testFile.close();
    return testUnit;
}

std::vector<Point2D> TestReader::loadPointsFromFile(std::fstream &test) {
    std::vector<Point2D> testUnit;
    int xCoordinate, yCoordinate;
    Point2D point;

    while(!test.eof()) {
        test >> xCoordinate;
        test >> yCoordinate;
        testUnit.push_back(Point2D(xCoordinate, yCoordinate));
    }
    return testUnit;
}

std::vector<Point2D> TestReader::readFromStandardInput() {
    int x, y;
    std::vector<Point2D> result;

    while(true) {
        std::cin >> x;
        if (std::cin.eof())  break;
        std::cin >> y;
        if (std::cin.eof())  break;
        result.push_back(Point2D(x, y));
    }
    std::cin.clear();
    return result;
}
