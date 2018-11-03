#include "TestReader.hpp"

TestReader::TestReader()
{ }

TestReader::~TestReader()
{ }

std::vector<Point2D> TestReader::readTestFile(std::string testFileName) {
    std::vector<Point2D> testUnit;
    std::fstream testFile;
    testFile.open(testFileName, std::fstream::in);
    testUnit = loadPoints(testFile);
    testFile.close();
    return testUnit;
}

std::vector<Point2D> TestReader::loadPoints(std::fstream &test) {
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
