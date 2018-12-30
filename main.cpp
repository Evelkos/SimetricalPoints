#include <iostream>
#include "./TestReader/TestReader.hpp"
#include "MyAlgorithm.hpp"
#include "BruteForceAlgorithm/BruteForceAlgorithm.hpp"

using namespace std;

int main()
{
    vector<Point2D> testUnit;
    MyAlgorithm alg;
    BruteForceAlgorithm brt;
    TestReader tr;
    testUnit = tr.readTestFile("./tests/test14.txt");

    std::cout << "Moj algorytm:" << std::endl;
    std::vector<Point2D> result = alg.getMinRectangle(testUnit);
    std::cout << "min x = " << result[0].getX() << " max y = " << result[0].getY() << " max x = " << result[1].getX() << " min y = " << result[1].getY() << std::endl;

    std::cout << "\n\nBrute force:" << std::endl;
    result.clear();
    result = brt.getMinRectangle(testUnit);
    std::cout << "min x = " << result[0].getX() << " max y = " << result[0].getY() << " max x = " << result[1].getX() << " min y = " << result[1].getY() << std::endl;

    return 0;
}
