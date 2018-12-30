#include <vector>
#include "Point2D/Point2D.hpp"

std::vector<Point2D> findExtremePointsOfRectangle(std::vector<Point2D>);
int countParimeter(std::vector<Point2D>);
int reflectPoints(int, std::vector<Point2D>&);
std::vector<Point2D> getIntersectionArea(std::vector<Point2D>, std::vector<Point2D>);
void compareMinRectangleWithNewRectangle(std::vector<Point2D>&, int&, std::vector<Point2D>);
//void updateMinRectangle(std::vector<Point2D> &minRectangle, int &parimeterOfMinRectangle, int &reflectedPointsOfMinRectangle,int combination, std::vector<Point2D> &points, int c1, int c2, int c3, int c4);
int countCosts(int combination, int cost1, int cost2, int cost3, int cost4);
void updateMinRectangle(std::vector<Point2D>&, int&, int&, int, std::vector<Point2D>&, int);
void updateMinRectangle(std::vector<Point2D>&, int&, int&, int, std::vector<Point2D>&);
bool isInArea(Point2D point, std::vector<Point2D> area);
void updateMinRectangle(std::vector<Point2D> &minRectangle, int &parimeterOfMinRectangle, int&reflectedPointsOfMinRectangle, int combination, std::vector<Point2D> &recVec, std::vector<Point2D> points);
