/*
Ewelina Chmielewska
283714
"Punkty symetryczne"
*/


#include "BruteForceAlgorithm.hpp"
#include "../RectangleFunctions.hpp"
#include <cstdio>   //itoa
#include <cstdlib> // abs
#include <cmath> // pow
#include <iostream> // cout, endl
#include <cstdio>

BruteForceAlgorithm::BruteForceAlgorithm()
{}

BruteForceAlgorithm::~BruteForceAlgorithm()
{}

std::vector<Point2D> BruteForceAlgorithm::getMinRectangle(std::vector<Point2D> points) {
    std::vector<Point2D> result;
    int minPerimeter = 0, reflectedPoints = 0;
    long long maxCombination = pow(2, points.size());
    for (long combination = 0 ; combination < maxCombination ; combination++)
       updateMinRectangle(result, minPerimeter, reflectedPoints, combination, points);
/*
    std::cout << "Brute force:" << std::endl;
    std::cout << "minPerimeter = " << minPerimeter << std::endl;
    std::cout << "reflectedPoints = " << reflectedPoints << std::endl << std::endl;
*/
    result = findExtremePointsOfRectangle(result);
    return result;
}
