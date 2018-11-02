#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <sstream>

#include "./Point2D/Point2D.hpp"
#include "./TestGenerator.hpp"

using namespace std;

int main()
{
    srand(time(NULL));      // potrzebne do generacji losowych wspolrzednych dla Point2D
    TestGenerator testGenerator;
    testGenerator.generateTest(0, 10);
    return 0;
}
