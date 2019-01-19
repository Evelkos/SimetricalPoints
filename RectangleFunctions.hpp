/*
Ewelina Chmielewska
283714
"Punkty symetryczne"
*/


#include <vector>
#include "Point2D/Point2D.hpp"

std::vector<Point2D> findExtremePointsOfRectangle(std::vector<Point2D>);
int countParimeter(std::vector<Point2D>);
int reflectPoints(int, std::vector<Point2D>&);
std::vector<Point2D> getIntersectionArea(std::vector<Point2D>, std::vector<Point2D>);
void updateMinRectangle(std::vector<Point2D>&, int&, int&, int, std::vector<Point2D>&);
void updateMinRectangle(std::vector<Point2D>&, int&, int&, int, std::vector<Point2D>&, std::vector<Point2D>&);
bool isInArea(Point2D point, std::vector<Point2D> area);
void showVec(std::vector<Point2D>);
void heapPermutation(int a[], int sizeVec, int n, std::vector<int>&);
