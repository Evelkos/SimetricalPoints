/*
Ewelina Chmielewska
283714
"Punkty symetryczne"
*/


#include <iostream>
#include <stdlib.h>
#include <vector>

#include "../Point2D/Point2D.hpp"


#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

class UserInterface
{
    public:
    void testMyAlgorithm (std::vector<Point2D>, std::vector<Point2D>&);
    void testBruteForceAlgorithm (std::vector<Point2D>, std::vector<Point2D>&);
    void testAlgorithms (std::vector<Point2D>, std::vector<Point2D>&, std::vector<Point2D>&);
    void testWithFileInput (std::string name);
    std::vector<Point2D> testWithStandardInput ();
    void testBothAlgorithms ();
    std::vector<Point2D> testWithRandomData (int, int, int, int, int);
    std::vector<Point2D> testWithRandomData (int);
    std::vector<Point2D> testWithTimeMeasurement (int, int, int, int);
    void test(int);

    private:
    void load(std::vector<int>&);
    void showResultsOfTestWithTimeMeasurement(std::string, std::vector<double>&, int, int, int, int);
};

#endif // POINT2D_HPP
