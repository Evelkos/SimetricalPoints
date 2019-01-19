/*
Ewelina Chmielewska
283714
"Punkty symetryczne"
*/


#include <cstring>
#include <ctime>
#include <chrono>

#include "UserInterface.hpp"
#include "../TestReader/TestReader.hpp"
#include "../BruteForceAlgorithm/BruteForceAlgorithm.hpp"
#include "../MyAlgorithm/MyAlgorithm.hpp"
#include "../RectangleFunctions.hpp"
#include "../TestGenerator/TestGenerator.hpp"

#define LINE_LENGTH 50
#define ACAPIT 10

#define MINX 0
#define MAXX 1000
#define MINY 0
#define MAXY 1000

void UserInterface::load(std::vector<int> &v)
{
  int v1, v2;		// 2 wartosci odpowiadajace wsp. punktu 2D
  while(true){
    std::cin>>v1>>v2;
    if(std::cin.eof()) break;
    v.push_back(v1);
    v.push_back(v2);
  }
}

void UserInterface::testMyAlgorithm (std::vector<Point2D> testUnit, std::vector<Point2D> &algRes) {
    MyAlgorithm alg;
    algRes = alg.getMinRectangle(testUnit);
}

void UserInterface::testBruteForceAlgorithm (std::vector<Point2D> testUnit, std::vector<Point2D> &algRes) {
    BruteForceAlgorithm brt;
    algRes = brt.getMinRectangle(testUnit);
}

void UserInterface::testAlgorithms (std::vector<Point2D> testUnit, std::vector<Point2D> &algRes, std::vector<Point2D> &brtRes) {
    MyAlgorithm alg;
    BruteForceAlgorithm brt;

    algRes = alg.getMinRectangle(testUnit);
    brtRes = brt.getMinRectangle(testUnit);
}

void showResults(std::vector<Point2D> algRes, std::vector<Point2D> brtRes) {
    std::cout << "Algorytm wlasny:\n";
    showVec(algRes);

    std::cout << "Brute force:\n";
    showVec(brtRes);

    std::cout << std::endl;
}

std::vector<Point2D> UserInterface::testWithStandardInput () {
     TestGenerator tg;
     std::vector<Point2D> testUnit, result;
     std::vector<int> numbers;

     load(numbers);
     testUnit = tg.createTestVector(numbers);
     testMyAlgorithm(testUnit, result);

     return result;
}

void UserInterface::testBothAlgorithms () {
     TestGenerator tg;
     std::vector<Point2D> testUnit, algResult, brtResult;
     std::vector<int> numbers;

     load(numbers);
     testUnit = tg.createTestVector(numbers);
     testAlgorithms(testUnit, algResult, brtResult);
     showResults(brtResult, algResult);
}

std::vector<Point2D> UserInterface::testWithRandomData (int pointsNumber, int minX, int maxX, int minY, int maxY) {
     TestGenerator tg;
     std::vector<Point2D> testUnit, result;

     testUnit = tg.generateTestVector(pointsNumber, minX, maxX, minY, maxY);
     testMyAlgorithm(testUnit, result);

     return result;
}

void UserInterface::testWithFileInput (std::string name) {
     TestReader reader;
     std::vector<Point2D> testUnit, algRes, brtRes;

     testUnit = reader.readTestFile(name);
     testAlgorithms(testUnit, algRes, brtRes);
     showResults(brtRes, algRes);
}

std::vector<Point2D> UserInterface::testWithRandomData (int pointsNumber) {
     return testWithRandomData (pointsNumber, MINX, MAXX, MINY, MAXY);
}

void UserInterface::showResultsOfTestWithTimeMeasurement
(std::string asymptote, std::vector<double> &durations, int pointsInFirstTest, int numberOfTests, int stepSize, int testsPerStep) {
     double tMedian = durations[(int)(durations.size()/2)];
     double asymptoteMedian = pointsInFirstTest + (int)(durations.size()/2) * stepSize;

     std::cout << "Algorytm z asymptotą O(" << asymptote << ")" << std::endl;
     for (unsigned i = 0 ; i < durations.size() ; i++) {
          std::cout << pointsInFirstTest + stepSize * i << " " << durations[i] << " ";
          std::cout << durations[i] * asymptoteMedian / ((pointsInFirstTest + i * stepSize) * tMedian) << std::endl;
     }
}

std::vector<Point2D> UserInterface::testWithTimeMeasurement (int pointsInFirstTest, int numberOfTests, int stepSize, int testsPerStep) {
     TestGenerator tg;
     std::vector<double> durations;
     double sum;
     std::vector<Point2D> testUnit, result;

     for (int i = 0 ; i < numberOfTests ; i++) {
          sum = 0;
          for(int j = 0 ; j < testsPerStep ; j++) {
               testUnit = tg.generateTestVector(pointsInFirstTest + stepSize * i);

               auto start = std::chrono::system_clock::now();
               testMyAlgorithm(testUnit, result);
               auto end = std::chrono::system_clock::now();

               std::chrono::duration<double> duration = end - start;
               sum += duration.count();
         }
         durations.push_back(sum/testsPerStep);
     }

     showResultsOfTestWithTimeMeasurement("T(n)", durations, pointsInFirstTest, numberOfTests, stepSize, testsPerStep);

     return result;
}

std::string toString(int value) {
    std::ostringstream os;
    os <<value;
    return os.str();
}

std::string getFileName(int i) {
    std::string fileName;
    fileName = "../tests/test" + toString(i);
    return fileName;
}
