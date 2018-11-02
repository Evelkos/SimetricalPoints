#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <sstream>

#include "./Point2D/Point2D.hpp"
#include "./TestGenerator.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));      // potrzebne do generacji losowych wspolrzednych dla Point2D
    TestGenerator testGenerator;

    if(argc == 1)   testGenerator.generateTests(1, 100);
    else if (argc == 2)     testGenerator.generateTests(1, atoi(argv[1]));
    else if (argc == 3)     testGenerator.generateTests(atoi(argv[1]), atoi(argv[2]));

    return 0;
}
