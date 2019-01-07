#include <string>
#include <vector>
#include <fstream>
#include "../Point2D/Point2D.hpp"

#ifndef TESTREADER_HPP
#define TESTREADER_HPP


class TestReader
{
    public:
        TestReader();
        ~TestReader();

        std::vector<Point2D> readTestFile(std::string testFileName);
        std::vector<Point2D> readFromStandardInput();

    protected:

    private:
        std::vector<Point2D> loadPointsFromFile(std::fstream &test);
};

#endif // TESTREADER_HPP
