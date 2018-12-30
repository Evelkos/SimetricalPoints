#include "RectangleFunctions.hpp"
#include <cmath> // pow
#include <iostream> // cout, endl
#include <cstdlib>

// funkcja zwraca dwa punkty skrajne prostokata: lewy gorny oraz prawy dolny
std::vector<Point2D> findExtremePointsOfRectangle(std::vector<Point2D> points) {
    std::vector<Point2D> result;
    if(points.size() < 1) return result;
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

// domyslnie ma przyjmowac prostokat otaczajacy punkty, ale jest zabezpieczona na wypadek przekazania zbioru punktow
int countPerimeter(std::vector<Point2D> points) {
    std::vector<Point2D> extremePoints = findExtremePointsOfRectangle(points);  // zabezpieczenie
    if (extremePoints.size() < 1) return -1;
    else if (extremePoints.size() == 1) return 0;

    int diffX = abs (extremePoints[0].getX() - extremePoints[1].getX());
    int diffY = abs (extremePoints[0].getY() - extremePoints[1].getY());
    return (diffX + diffY) * 2;
}

int reflectPoints(int combination, std::vector<Point2D> &points) {
    int reflectedPoints = 0;
    int binaryPointer = 1; // reprezentuje liczbe binarna, w ktorej jedynka znajduje sie na miejscu wskazywanym przez pointIndex
    for (unsigned pointIndex = 0 ; binaryPointer <= combination ; pointIndex++) {
        if ((binaryPointer & combination) != 0) {
            points[pointIndex].reflectOverYEqualsX();
            reflectedPoints++;
        }
        binaryPointer = binaryPointer << 1;
    }
    return reflectedPoints;
}

std::vector<Point2D> getIntersectionArea(std::vector<Point2D> rec1, std::vector<Point2D> rec2) {
    std::vector<Point2D> per1, per2, result;    // per1, per2 - obwody
    per1 = findExtremePointsOfRectangle(rec1);
    per2 = findExtremePointsOfRectangle(rec2);
    if(per1.size() < 1 ||  per2.size() < 1) return result;

    int upperLeftX = std::max(per1[0].getX(), per2[0].getX());
    int upperLeftY = std::min(per1[0].getY(), per2[0].getY());
    int bottomRightX = std::min(per1[1].getX(), per2[1].getX());
    int bottomRightY = std::max(per1[1].getY(), per2[1].getY());

    if(upperLeftX > bottomRightX || upperLeftY < bottomRightY) return result;

    Point2D upperLeft(upperLeftX, upperLeftY);
    Point2D bottomRight(bottomRightX, bottomRightY);
    result.push_back(upperLeft);
    result.push_back(bottomRight);
    return result;
}

void showVec(std::vector<Point2D> vec) {
    for(unsigned i = 0 ; i < vec.size() ; i++) {
        std::cout << "(" << vec[i].getX() << " , " << vec[i].getY() << ")" << std::endl;
    }
}

void chooseSmallerRectangle(std::vector<Point2D> &minRectangle, int &perimeterOfminRectangle, int &reflectedPointsOfMinRectangle, std::vector<Point2D> points, int reflectedPoints) {
    std::vector<Point2D> newRectangle = findExtremePointsOfRectangle(points);
    int perimeterOfNewRectangle = countPerimeter(newRectangle);
/*
    std::cout << "Prostokat" << std::endl;
    showVec(newRectangle);
    std::cout << "perimeter = " << perimeterOfNewRectangle << std::endl;
    std::cout << "reflected = " << reflectedPoints << std::endl << std::endl;
*/
    if (minRectangle.size() < 1 || perimeterOfNewRectangle < perimeterOfminRectangle || (perimeterOfNewRectangle == perimeterOfminRectangle && reflectedPointsOfMinRectangle > reflectedPoints)) {
        minRectangle.clear();
        minRectangle = newRectangle;
        perimeterOfminRectangle = perimeterOfNewRectangle;
        reflectedPointsOfMinRectangle = reflectedPoints;
    }
}

bool isInArea(Point2D point, std::vector<Point2D> area) {
    std::vector<Point2D> vec;
    vec.push_back(point);
    return getIntersectionArea(vec, area).size() > 0;
}

int countPointsInArea(std::vector<Point2D> points, std::vector<Point2D> area) {
    int sum = 0;
    area = findExtremePointsOfRectangle(area); // na wszelki wypadek
    for(unsigned i = 0 ; i < points.size() ; i++) {
        if(isInArea(points[i], area))
            sum++;
    }
    return sum;
}

void chooseSmallerRectangleXXX(std::vector<Point2D> &minRectangle, int &perimeterOfminRectangle, int &reflectedPointsOfMinRectangle, std::vector<Point2D> newRectangle, std::vector<Point2D> points) {
    int perimeterOfNewRectangle = countPerimeter(newRectangle);
/*
    std::cout << "Prostokat" << std::endl;
    showVec(newRectangle);
    std::cout << "perimeter = " << perimeterOfNewRectangle << std::endl;
    std::cout << "reflected = " << reflectedPoints << std::endl << std::endl;
*/
    if (minRectangle.size() < 1 || perimeterOfNewRectangle < perimeterOfminRectangle) {
        unsigned pointsOutNewRec = points.size() - countPointsInArea(points, newRectangle);
        minRectangle.clear();
        minRectangle = newRectangle;
        perimeterOfminRectangle = perimeterOfNewRectangle;
        reflectedPointsOfMinRectangle = pointsOutNewRec;
    }
    else if (minRectangle.size() < 1 || perimeterOfNewRectangle == perimeterOfminRectangle) {
        unsigned pointsOutNewRec = points.size() - countPointsInArea(points, newRectangle);
        if(pointsOutNewRec < reflectedPointsOfMinRectangle) {
            minRectangle.clear();
            minRectangle = newRectangle;
            perimeterOfminRectangle = perimeterOfNewRectangle;
            reflectedPointsOfMinRectangle = pointsOutNewRec;
        }
    }
}

/*
void updateMinRectangle(std::vector<Point2D> &minRectangle, int &parimeterOfMinRectangle, int&reflectedPointsOfMinRectangle, int combination, std::vector<Point2D> &points, int cost) {
    if(combination > pow(2, points.size())) return;
    reflectPoints(combination, points);
    chooseSmallerRectangleXXX(minRectangle, parimeterOfMinRectangle, reflectedPointsOfMinRectangle, points, cost);
    reflectPoints(combination, points);
}
*/

void updateMinRectangle(std::vector<Point2D> &minRectangle, int &parimeterOfMinRectangle, int&reflectedPointsOfMinRectangle, int combination, std::vector<Point2D> &recVec, std::vector<Point2D> points) {
    if(combination > pow(2, recVec.size())) return;
    reflectPoints(combination, recVec);
    std::vector<Point2D> newRectangle = findExtremePointsOfRectangle(recVec);
    reflectPoints(combination, recVec);
    chooseSmallerRectangleXXX(minRectangle, parimeterOfMinRectangle, reflectedPointsOfMinRectangle, newRectangle, points);
}

void updateMinRectangle(std::vector<Point2D> &minRectangle, int &parimeterOfMinRectangle, int&reflectedPointsOfMinRectangle, int combination, std::vector<Point2D> &points) {
    if(combination > pow(2, points.size())) return;
    int cost = reflectPoints(combination, points);
    chooseSmallerRectangle(minRectangle, parimeterOfMinRectangle, reflectedPointsOfMinRectangle, points, cost);
    reflectPoints(combination, points);
}
