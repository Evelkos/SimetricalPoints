#include "../Point2D/Point2D.hpp"
#include <vector>

#ifndef BRUTEFORCEALGORITHM_HPP
#define BRUTEFORCEALGORITHM_HPP


class BruteForceAlgorithm
{
    public:
        BruteForceAlgorithm();
        virtual ~BruteForceAlgorithm();
        std::vector<Point2D> getMinRectangle(std::vector<Point2D> points);

    protected:

    private:
};

#endif // BRUTEFORCEALGORITHM_HPP
