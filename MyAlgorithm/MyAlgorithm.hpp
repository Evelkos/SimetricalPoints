#include "../RectangleFunctions.hpp"

#ifndef MYALGORITHM_HPP
#define MYALGORITHM_HPP


class MyAlgorithm
{
    public:
        MyAlgorithm();
        virtual ~MyAlgorithm();
        std::vector<Point2D> getMinRectangle(std::vector<Point2D>);
    protected:
    void checkCases(std::vector<Point2D>&, std::vector<Point2D>&, int, int, int, int);
    int countCosts(int, int, int, int, int);
    void dividePointsIntoUpperAndBottomGroup(std::vector<Point2D>, std::vector<Point2D>&, std::vector<Point2D>&);
    std::vector<Point2D> findMinRectangle(std::vector<Point2D>&, int, int, int, int);
   // bool isInArea(Point2D, std::vector<Point2D>);
    std::vector<Point2D> mergeVectors(std::vector<Point2D>&, std::vector<Point2D>&, std::vector<Point2D>&, std::vector<Point2D>&);
    std::vector<Point2D> separateIntersectionPointsFromRectangles(std::vector<Point2D>&, std::vector<Point2D>&);
    void showVector(std::vector<Point2D>);
    std::vector<Point2D> sumVectors (std::vector<Point2D>&, std::vector<Point2D>&);
    void reflectRectangle(std::vector<Point2D>&, std::vector<Point2D>);
    void checkCases(std::vector<Point2D> &result, std::vector<Point2D> &recVec, int cost1, int cost2, int cost3, int cost4, std::vector<Point2D> points);
    std::vector<Point2D> findMinRectangle(std::vector<Point2D> &rectanglesSurroundingConvexHulls, int cost1, int cost2, int cost3, int cost4, std::vector<Point2D> points);

    private:
};

#endif // MYALGORITHM_HPP
