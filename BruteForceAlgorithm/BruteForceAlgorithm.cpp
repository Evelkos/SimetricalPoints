#include "BruteForceAlgorithm.hpp"
#include <cstdlib> // abs
#include <cmath> // pow
#include <iostream> // cout, endl

BruteForceAlgorithm::BruteForceAlgorithm()
{}

BruteForceAlgorithm::~BruteForceAlgorithm()
{}

// funkcja zwraca dwa punkty skrajne prostokata: lewy gorny oraz prawy dolny
std::vector<Point2D> findExtremePointsOfRectangle(std::vector<Point2D> points) {
    std::vector<Point2D> result;
    int minX, maxX, minY, maxY;
    minX = maxX = points[0].getX();
    minY = maxY = points[0].getY();
    for (unsigned i = 1 ; i < points.size() ; i++) {
        int currX = points[i].getX();
        int currY = points[i].getY();
        if (minX > currX) minX = currX;
        else if (maxX < currX) maxX = currX;
        if (minY > currY) minY = currY;
        else if (maxY < currY) maxY = currY;
    }
    result.push_back(Point2D(minX, maxY));
    result.push_back(Point2D(maxX, minY));
    return result;
}

// na podstawie punktow skrajnych funkcja oblicza obwod prostokata
int countParimeter(std::vector<Point2D> extremePoints) {
    if (extremePoints.size() != 2) return -1;
    int diffX = abs (extremePoints[0].getX() - extremePoints[1].getX());
    int diffY = abs (extremePoints[0].getY() - extremePoints[1].getY());
    return (diffX + diffY) * 2;
}

void reflectPoints(int combination, std::vector<Point2D> &points) {
    long long binaryPointer = 1; // reprezentuje liczbe binarna, w ktorej jedynka znajduje sie na miejscu wskazywanym przez pointIndex
    for (int pointIndex = 0 ; binaryPointer <= combination ; pointIndex++) {
        if ((binaryPointer & combination) != 0) points[pointIndex].reflectOverYEqualsX();
        binaryPointer = binaryPointer << 1;
    }
}

void compareMinRectangleWithNewRectangle(std::vector<Point2D> &minRectangle, int &parimeterOfminRectangle, std::vector<Point2D> points) {
    std::vector<Point2D> newRectangle;
    int parimeterOfNewRectangle;
    newRectangle = findExtremePointsOfRectangle(points);
    parimeterOfNewRectangle = countParimeter(newRectangle);
    if (minRectangle.size() < 2 || parimeterOfminRectangle < 0 || parimeterOfNewRectangle < parimeterOfminRectangle) {
        minRectangle.clear();
        minRectangle = newRectangle;
        parimeterOfminRectangle = parimeterOfNewRectangle;
    }
}

void updateMinRectangle(std::vector<Point2D> &minRectangle, int &parimeterOfminRectangle, int combination, std::vector<Point2D> &points) {
    reflectPoints(combination, points);
    compareMinRectangleWithNewRectangle(minRectangle, parimeterOfminRectangle, points);
    reflectPoints(combination, points);

}

std::vector<Point2D> BruteForceAlgorithm::getMinRectangle(std::vector<Point2D> points) {
    std::vector<Point2D> result;
    int minParimeter = -1;
    int maxCombination = pow(2, points.size());

    for (int combination = 1 ; combination < maxCombination ; combination++) {
        updateMinRectangle(result, minParimeter, combination, points);
    }

    std::cout << "min x = " << result[0].getX() << " max y = " << result[0].getY() << " max x = " << result[1].getX() << " min y = " << result[1].getY() << std::endl;
    return result;
}
