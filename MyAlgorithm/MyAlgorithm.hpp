/*
Ewelina Chmielewska
283714
"Punkty symetryczne"
*/


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
    void checkCases(std::vector<Point2D>&, std::vector<Point2D>&, int, int, int, int, std::vector<Point2D>);
    void dividePointsIntoUpperAndBottomGroup(std::vector<Point2D>, std::vector<Point2D>&, std::vector<Point2D>&);
    std::vector<Point2D> mergeVectors(std::vector<Point2D>&, std::vector<Point2D>&, std::vector<Point2D>&, std::vector<Point2D>&);
    std::vector<Point2D> separateIntersectionPointsFromRectangles(std::vector<Point2D>&, std::vector<Point2D>&);
    void showVector(std::vector<Point2D>);
    std::vector<Point2D> sumVectors (std::vector<Point2D>&, std::vector<Point2D>&);
    void reflectRectangle(std::vector<Point2D>&, std::vector<Point2D>);
    std::vector<Point2D> findMinRectangle(std::vector<Point2D> &, int, int, int, int, std::vector<Point2D>);

    private:
};

#endif // MYALGORITHM_HPP
