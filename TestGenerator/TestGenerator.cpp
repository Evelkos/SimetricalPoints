#include "TestGenerator.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

#define MINX 0
#define MAXX 100
#define MINY 0
#define MAXY 100

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

std::string TestGenerator::createTestFile(int numberOfPoints, int minX, int maxX, int minY, int maxY) {
    std::fstream testFile;
    std::vector<Point2D> points;
    std::string name = createTestname(++lastTestID);

    testFile.open(name, std::ios::out);
    points = createTestVector(numberOfPoints, minX, maxX, minY, maxY);
    savePointsToTheFile(testFile, points);
    testFile.close();

    return name;
}

void TestGenerator::savePointsToTheFile(std::fstream &testFile, std::vector<Point2D> points) {
    for (unsigned i = 0 ; i < points.size() ; i++) {
        testFile << points[i].getX() << ' ' << points[i].getY() << '\n';
    }
}

std::vector<Point2D> TestGenerator::createTestVector(int numberOfPoints, int minX, int maxX, int minY, int maxY) {
    std::vector<Point2D> result;
    for (int i = 0 ; i < numberOfPoints ; i++) {
        Point2D point;
        point.setRandomXY(minX, maxX, minY, maxY);
        result.push_back(point);
    }
    return result;
}

std::vector<Point2D> TestGenerator::createTestVector(int numberOfPoints) {
    return createTestVector(numberOfPoints, MINX, MAXX, MINY, MAXY);
}
