/*
Ewelina Chmielewska
283714
"Punkty symetryczne"
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "./TestReader/TestReader.hpp"
#include "./TestGenerator/TestGenerator.hpp"
#include "./MyAlgorithm/MyAlgorithm.hpp"
#include "BruteForceAlgorithm/BruteForceAlgorithm.hpp"
#include "./UI/UserInterface.hpp"

#define MAX_TEST_NUMBER 100
#define MIN_TEST_NUMBER 1

std::string int_to_string(int value) {
    std::ostringstream os;
    os <<value;
    return os.str();
}

std::string getTestname(int testNumber) {
    std::string name = "./tests/test" + int_to_string(testNumber) + ".txt";
    return name;
}

void showResult(std::vector<Point2D> result) {
    for(unsigned i = 0 ; i < result.size() ; i++) {
        std::cout << result[i].getX() << " " << result[i].getY() << std::endl;
    }
}

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));
    UserInterface ur;

    if(argc == 1) {
       std::cout << "Niewlasciwy tryb uruchomienia programu. Prosimy zapoznac sie z plikiem README.txt umieszczonym w folderze MyAlgorithm" << std::endl;
    }

    if(argc > 1) {
        int mode = atoi(argv[1]);
        if (mode == 1) {                // standard input
            std::vector<Point2D> result;
            result = ur.testWithStandardInput();
            showResult(result);
        }

        else if (mode == 2) {		// test with random data
            std::vector<Point2D> result;
            if(argc == 3) {
                int numberOfPoints = atoi(argv[2]);
                result = ur.testWithRandomData(numberOfPoints);
                showResult(result);
            }
            else if(argc == 7) {
                int numberOfPoints = atoi(argv[2]);
                int minX = atoi(argv[3]);
                int maxX = atoi(argv[4]);
                int minY = atoi(argv[5]);
                int maxY = atoi(argv[6]);
                result = ur.testWithRandomData(numberOfPoints, minX, maxX, minY, maxY);
                showResult(result);
            }
            else
                std::cout << "ERROR: Niewlasciwa liczba argumentow" << std::endl;
        }

        else if (mode == 3) {		// test with time measurement
            if (argc >= 6) {
                int pointsInFirstTest = atoi(argv[2]);
                int numberOfTests = atoi(argv[3]);
                int stepSize = atoi(argv[4]);
                int testsPerStep = atoi(argv[5]);
                ur.testWithTimeMeasurement(pointsInFirstTest, numberOfTests, stepSize, testsPerStep);
            }
            else
                std::cout << "ERROR: Niewlasciwa liczba argumentow" << std::endl;
        }

        else if(mode == 4) {
            string name;
            for(int i = 1 ; i < MAX_TEST_NUMBER ; i++) {
                std::cout << "Test " << i << ":" << std::endl;
                name = getTestname(i);
                ur.testWithFileInput(name);
            }
        }

        else if(mode == 5) {
                ur.testWithFileInput(argv[2]);
        }
    }

    return 0;
}
