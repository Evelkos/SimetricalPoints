/*
Ewelina Chmielewska
283714
"Punkty symetryczne"
*/


#include <iostream>
#include "MyAlgorithm.hpp"

MyAlgorithm::MyAlgorithm() {}
MyAlgorithm::~MyAlgorithm(){}

void MyAlgorithm::checkCases(std::vector<Point2D> &result, std::vector<Point2D> &recVec, int cost1, int cost2, int cost3, int cost4, std::vector<Point2D> points) {
    int combination[] = {0, 3, 12, 15, 48, 51, 60, 63, 192, 195, 204, 207, 240, 243, 252};  //koszt staly sprawdzenia zbyt duzej kombinacji
    int reflectedPointsNum = -1, minPerimeret = -1;
    int combinationLength = sizeof(combination) / sizeof(combination[1]);
    for (int i = 0 ; i < combinationLength ; i++)
        updateMinRectangle(result, minPerimeret, reflectedPointsNum, combination[i], recVec, points);
/*
    std::cout << "Algorytm:" << std::endl;
    std::cout << "minPerimeret = " << minPerimeret << std::endl;
    std::cout << "reflectedPointsNum = " << reflectedPointsNum << std::endl << std::endl;
*/
}

void MyAlgorithm::dividePointsIntoUpperAndBottomGroup(std::vector<Point2D> points, std::vector<Point2D> &upG, std::vector<Point2D> &botG) {
    for(unsigned i = 0 ; i < points.size() ; i++){
        if(points[i].getX() < points[i].getY()) upG.push_back(points[i]);
        else botG.push_back(points[i]);
    }
}

std::vector<Point2D> MyAlgorithm::findMinRectangle(std::vector<Point2D> &rectanglesSurroundingConvexHulls, int cost1, int cost2, int cost3, int cost4, std::vector<Point2D> points) {
    std::vector<Point2D> result;
    checkCases(result, rectanglesSurroundingConvexHulls, cost1, cost2, cost3, cost4, points);
    return result;
}

std::vector<Point2D> MyAlgorithm::getMinRectangle(std::vector<Point2D> points) {
    if (points.size() == 0 ) return std::vector<Point2D>();
    std::vector<Point2D> upperG, bottomG, upperRec, bottomRec, result;

    //podzial punktow na zb. powyzej i ponizej prostej y = x. Ziobry A i B
    dividePointsIntoUpperAndBottomGroup(points, upperG, bottomG);

    //wyznaczenie prostokatow otaczajacych zbiory A i B -> RA, RB
    upperRec = findExtremePointsOfRectangle(upperG);
    bottomRec = findExtremePointsOfRectangle(bottomG);

    //odbicie wzgledem prostej y = x prostokata RA -> powstaje RA'
    reflectRectangle(upperRec, std::vector<Point2D>());
    std::vector<Point2D> intersectionAfterUpperRecReflection, intersUpprG, intersBottG;    //4

    //wyznaczenie czesci wspolnej prostokatow RA' i RB
    intersectionAfterUpperRecReflection = getIntersectionArea(upperRec, bottomRec);        //5

    int intersectionAfterUpperRecReflectionPNum = intersectionAfterUpperRecReflection.size();
    //wydzielenie zbioru D
    intersBottG = separateIntersectionPointsFromRectangles(bottomG, intersectionAfterUpperRecReflection);
    for (int i = 0 ; i < intersectionAfterUpperRecReflectionPNum ; i++) intersBottG.pop_back();

    //wyznaczenie prostokata RD
    intersectionAfterUpperRecReflection.clear();
    intersectionAfterUpperRecReflection = getIntersectionArea(upperRec, bottomRec);
    intersectionAfterUpperRecReflectionPNum = intersectionAfterUpperRecReflection.size();
    reflectRectangle(upperRec, std::vector<Point2D>());
    reflectRectangle(intersectionAfterUpperRecReflection, std::vector<Point2D>());

    //wydzielenie zbioru E
    intersUpprG = separateIntersectionPointsFromRectangles(upperG, intersectionAfterUpperRecReflection);
    for (int i = 0 ; i < intersectionAfterUpperRecReflectionPNum ; i++) intersUpprG.pop_back();

    //wyznaczenie prostokata RE
    std::vector<Point2D> intersUpperRec, intersBottomRec;
    upperRec = findExtremePointsOfRectangle(upperG);
    bottomRec = findExtremePointsOfRectangle(bottomG);
    intersUpperRec = findExtremePointsOfRectangle(intersUpprG);
    intersBottomRec = findExtremePointsOfRectangle(intersBottG);

    //uzupelnianie pustych prostokatow RA, RB, RD, RE i utworzenie prostokata pomocniczego
    if(upperRec.size() == 0) { upperRec.push_back(points[0]); upperRec.push_back(points[0]); }
    if(bottomRec.size() == 0) { bottomRec.push_back(points[0]); bottomRec.push_back(points[0]); }
    if(intersUpperRec.size() == 0) { intersUpperRec.push_back(points[0]); intersUpperRec.push_back(points[0]); }
    if(intersBottomRec.size() == 0) { intersBottomRec.push_back(points[0]); intersBottomRec.push_back(points[0]); }
    std::vector<Point2D> rectanglesSurroundingConvexHulls = mergeVectors(upperRec, bottomRec, intersUpperRec, intersBottomRec);

    //wyznaczenie wyniku i unormowanie go
    result = findMinRectangle(rectanglesSurroundingConvexHulls, upperG.size(), bottomG.size(), intersUpprG.size(), intersBottG.size(), points);
    result = findExtremePointsOfRectangle(result);

    return result;
}

std::vector<Point2D> MyAlgorithm::mergeVectors(std::vector<Point2D> &r1, std::vector<Point2D> &r2, std::vector<Point2D> &r3, std::vector<Point2D> &r4) {
    std::vector<Point2D> result = sumVectors(r1, r2);
    result = sumVectors(result, r3);
    result = sumVectors(result, r4);
    return result;
}

std::vector<Point2D> MyAlgorithm::sumVectors (std::vector<Point2D> &vec1, std::vector<Point2D> &vec2) {
    std::vector<Point2D> result = vec1;
    for(unsigned i = 0 ; i < vec2.size() ; i++) result.push_back(vec2[i]);
    return result;
}

std::vector<Point2D> MyAlgorithm::separateIntersectionPointsFromRectangles(std::vector<Point2D> &rec1, std::vector<Point2D> &rec2){
    std::vector<Point2D> intersectionArea, rec1Tmp, rec2Tmp, inP;
    intersectionArea = getIntersectionArea(rec1, rec2);
    if(intersectionArea.size() > 0) {
        for(unsigned i = 0 ; i < rec1.size() ; i++) {
            if(isInArea(rec1[i], intersectionArea)) inP.push_back(rec1[i]);
            else rec1Tmp.push_back(rec1[i]);
        }
        for(unsigned i = 0 ; i < rec2.size() ; i++) {
            if(isInArea(rec2[i], intersectionArea)) inP.push_back(rec2[i]);
            else rec2Tmp.push_back(rec2[i]);
        }
        rec1.clear();
        rec2.clear();
        rec1 = rec1Tmp;
        rec2 = rec2Tmp;
    }
    return inP;
}

void MyAlgorithm::reflectRectangle(std::vector<Point2D> &rectangle, std::vector<Point2D> excludedArea) {
    if(rectangle.size() <= 0) return;
    excludedArea = findExtremePointsOfRectangle(excludedArea);
    for(unsigned i = 0 ; i < rectangle.size() ; i++) {
        if(excludedArea.size() < 1 || !isInArea(rectangle[i], excludedArea))
            rectangle[i].reflectOverYEqualsX();
    }
}
