/*
Ewelina Chmielewska
283714
"Punkty symetryczne"
*/


#include "RectangleFunctions.hpp"
#include <cmath> // pow
#include <iostream> // cout, endl
#include <cstdlib>
#include <algorithm>

std::vector<int> permutations;

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
    std::vector<Point2D> extremePoints = findExtremePointsOfRectangle(points); 
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


int countPointsOutOfArea(std::vector<Point2D> points, std::vector<Point2D> area) {
    int sum = 0;
    area = findExtremePointsOfRectangle(area);
    for(unsigned i = 0 ; i < points.size() ; i++) {
        if(isInArea(points[i], area) == false)
            sum++;   
    }
    return sum;
}

std::vector<Point2D> compare(std::vector<Point2D> &minRectangle, int &perimeterOfminRectangle, int &reflectedPointsOfMinRectangle, std::vector<Point2D> newRectangle, std::vector<Point2D> points) {
    int perimeterOfNewRectangle = countPerimeter(newRectangle);
    std::vector<Point2D> result;

    if (minRectangle.size() < 1 || perimeterOfNewRectangle < perimeterOfminRectangle) {
        unsigned pointsOutNewRec = countPointsOutOfArea(points, newRectangle);
        minRectangle.clear();
        minRectangle = newRectangle;
        perimeterOfminRectangle = perimeterOfNewRectangle;
        reflectedPointsOfMinRectangle = pointsOutNewRec;
        result.push_back(newRectangle[0]);
        result.push_back(newRectangle[1]);
    }
    else if (minRectangle.size() < 1 || perimeterOfNewRectangle == perimeterOfminRectangle) {
        unsigned pointsOutNewRec = countPointsOutOfArea(points, newRectangle);

        if(pointsOutNewRec <= reflectedPointsOfMinRectangle) {
            minRectangle.clear();
            minRectangle = newRectangle;
            perimeterOfminRectangle = perimeterOfNewRectangle;
            reflectedPointsOfMinRectangle = pointsOutNewRec;
            result.push_back(newRectangle[0]);
            result.push_back(newRectangle[1]);
        }
    }
    return result;
}

bool areAllPointsInRec(std::vector<Point2D> rec, std::vector<Point2D> &points) {
    bool flag = true;
    for(unsigned i = 0 ; i < points.size() ; i++) {
        if(isInArea(points[i], rec) == false) {
            points[i].reflectOverYEqualsX();
            if(isInArea(points[i], rec) == false) {flag = false; break;}
            points[i].reflectOverYEqualsX();
        }
    }
    return flag;
}

void heapPermutation(int a[], int sizeVec, int n, std::vector<int> &perm)
{
    if (sizeVec == 1) {
        for(int i = 0 ; i < n ; i++)
        perm.push_back(a[i]);
        return;
    }

    for (int i=0; i<sizeVec; i++) {
        heapPermutation(a,sizeVec-1,n, perm);
        if (sizeVec%2==1)
            std::swap(a[0], a[sizeVec-1]);
        else
            std::swap(a[i], a[sizeVec-1]);
    }
}

std::vector<int> getPermutationsOfFourElements() {
    int a[] = {0, 1, 2, 3};
    std::vector<int> perm;
    int n = sizeof a/sizeof a[0];
    heapPermutation(a, n, n, perm);
    return perm;
}


void updateMinRectangle(std::vector<Point2D> &minRectangle, int &parimeterOfMinRectangle, int&reflectedPointsOfMinRectangle, int combination, std::vector<Point2D> &recVec, std::vector<Point2D> &points) {
    bool flag;
    if(combination > pow(2, recVec.size())) return;
    reflectPoints(combination, recVec);
    std::vector<Point2D> newRectangle = findExtremePointsOfRectangle(recVec);
    reflectPoints(combination, recVec);
    std::vector<Point2D> recToCheck = compare(minRectangle, parimeterOfMinRectangle, reflectedPointsOfMinRectangle, newRectangle, points);

    //fragment zbudowany na podstawie obserwacji
    if(recToCheck.size() > 0) {
        std::vector<int> perm = getPermutationsOfFourElements();
        int factors[4];
        factors[0] = recToCheck[0].getX();
        factors[1] = recToCheck[0].getY();
        factors[2] = recToCheck[1].getX();
        factors[3] = recToCheck[1].getY();
        for(unsigned i = 0 ; i < perm.size() / 4 ; i+=4) {
            std::vector<Point2D> rec;
            rec.push_back(Point2D(factors[perm[i]],factors[perm[i+1]]));
            rec.push_back(Point2D(factors[perm[i+2]],factors[perm[i+3]]));
            if(countPerimeter(rec) <= parimeterOfMinRectangle && areAllPointsInRec(rec, points))
                compare(minRectangle, parimeterOfMinRectangle, reflectedPointsOfMinRectangle, rec, points);
        }
    }

}

void updateMinRectangle(std::vector<Point2D> &minRectangle, int &parimeterOfMinRectangle, int&reflectedPointsOfMinRectangle, int combination, std::vector<Point2D> &points) {
    if(combination > pow(2, points.size())) return;
    int cost = reflectPoints(combination, points);
    chooseSmallerRectangle(minRectangle, parimeterOfMinRectangle, reflectedPointsOfMinRectangle, points, cost);
    reflectPoints(combination, points);
}

