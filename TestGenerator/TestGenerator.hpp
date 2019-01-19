/*
Ewelina Chmielewska
283714
"Punkty symetryczne"
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../Point2D/Point2D.hpp"

#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H

class TestGenerator
{
    private:
    static int lastTestID;

    public:
        TestGenerator();
        ~TestGenerator();
        std::string createTestFile(int numberOfPoints, int minX, int maxX, int minY, int maxY);
        std::vector<Point2D> generateTestVector(int, int, int, int, int);
        std::vector<Point2D> generateTestVector(int);
        std::vector<Point2D> createTestVector(std::vector<int>);
    private:
        void savePointsToTheFile(std::fstream&, std::vector<Point2D>);
};

#endif // TESTGENERATOR_H
