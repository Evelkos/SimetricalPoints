#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <strstream>

#include "UserInterface.hpp"
#include "../Point2D/Point2D.hpp"
#include "../TestReader/TestReader.hpp"
#include "../BruteForceAlgorithm/BruteForceAlgorithm.hpp"
#include "../MyAlgorithm/MyAlgorithm.hpp"
#include "../RectangleFunctions.hpp"
#include "../TestGenerator/TestGenerator.hpp"

#define LINE_LENGTH 50
#define ACAPIT 10

void showMainMenu() {
    std::cout << "\nTryb wykonania:" << std::endl;
    std::cout << "1) Wejscie z pliku" << std::endl;
    std::cout << "2) Wejscie standardowe" << std::endl;
    std::cout << "3) Dane generowane automatycznie" << std::endl;
    std::cout << "4) Dane generowane automatycznie z pomiarami czasu" << std::endl;
}

std::string getFileName() {
    std::string fileName;
    std::cout << "Podaj nazwe pliku, z ktorego maja byc pobrane dane" << std::endl;
    std::cout << "Plik: ";
    std::cin >> fileName;
    std::cin.clear();
    std::cin.ignore(100, '\n');
    return fileName;
}

void getLimits(int &numberOfTests, int &numberOfPoints, int &minX, int &maxX, int &minY, int &maxY) {
    std::cout << "Podaj liczbe testow\nLiczba testow = ";
    std::cin >> numberOfTests;
    std::cout << "Podaj liczbe punktow w tescie\nLiczba punktow = ";
    std::cin >> numberOfPoints;
    std::cout << "Podaj minimalna wartosc wspolrzednej x = ";
    std::cin >> minX;
    std::cout << "Podaj maksymalna wartosc wspolrzednej x = ";
    std::cin >> maxX;
    std::cout << "Podaj minimalna wartosc wspolrzednej y = ";
    std::cin >> minY;
    std::cout << "Podaj maksymalna wartosc wspolrzednej y = ";
    std::cin >> maxY;
    std::cin.clear();
    while(getchar() != '\n');
}

void printLine(std::string word1, std::string word2, int lineLength, int diff) {
    for(unsigned i = 0 ; i < ACAPIT ; i++) std::cout << " ";
    std::cout << word1;
    for(unsigned i = 0 ; i < lineLength - ACAPIT - word1.size() ; i++) std::cout << " ";
    std::cout << word2 << std::endl;
}

std::string toString(int num) {
    std::stringstream s;
    s << num;
    return s.str();
}

void showResultsInTable(std::string name1, std::string name2, std::vector<int> res1, std::vector<int> res2) {
    printLine(name1, name2, LINE_LENGTH, 0);
    for (unsigned i = 0 ; i < res1.size() ; i++) {
        std::string w1, w2;
        w1 += toString(res1[i]);
        w2 += toString(res2[i]);
        printLine(w1, w2, LINE_LENGTH, 0);
    }
}

void showResults(std::vector<Point2D> algRes, std::vector<Point2D> brtRes) {
    std::cout << "Algorytm wlasny:\n";
    showVec(algRes);

    std::cout << "\nBrute force:\n";
    showVec(algRes);
}

void testAlgorithms (std::vector<Point2D> testUnit, std::vector<Point2D> &algRes, std::vector<Point2D> &brtRes, int &algTime, int &brtTime) {
    MyAlgorithm alg;
    BruteForceAlgorithm brt;
    time_t clock;

    clock = time(NULL);
    algRes = alg.getMinRectangle(testUnit);
    algTime = time(NULL) - clock;

    clock = time(NULL);
    brtRes = brt.getMinRectangle(testUnit);
    brtTime = time(NULL) - clock;
}

void testAlgorithms (std::vector<Point2D> testUnit, std::vector<Point2D> &algRes, std::vector<Point2D> &brtRes) {
    MyAlgorithm alg;
    BruteForceAlgorithm brt;

    algRes = alg.getMinRectangle(testUnit);
    brtRes = brt.getMinRectangle(testUnit);
}

void testWithFileInput() {
    std::vector<Point2D> testUnit, bruteForceResult, myAlgorithmResult;
    std::string fileName;
    TestReader tr;

    fileName = getFileName();
    testUnit = tr.readTestFile(fileName);
    testAlgorithms(testUnit, myAlgorithmResult, bruteForceResult);
    showResults(myAlgorithmResult, bruteForceResult);
}

void testWithStandardInput() {
    std::vector<Point2D> testUnit, bruteForceResult, myAlgorithmResult;
    TestReader tr;

    std::cout << "Podaj punkty, ktore maja sie znalezc na plaszczyznie:\n";
    std::cout << "Nacisnij Ctrl+Z aby zakonczyc\n";

    testUnit = tr.readFromStandardInput();
    testAlgorithms(testUnit, bruteForceResult, myAlgorithmResult);
    showResults(myAlgorithmResult, bruteForceResult);
}

void testWithRandomData() {
    std::vector<Point2D> testUnit, bruteForceResult, myAlgorithmResult;
    TestGenerator tg;
    int numberOfTests, numberOfPoints, minX, maxX, minY, maxY;

    getLimits(numberOfTests, numberOfPoints, minX, maxX, minY, maxY);
    for (int i = 1 ; i <= numberOfTests ; i++) {
        std::cout << "Test " << i << ":" << std::endl;
        testUnit = tg.createTestVector(numberOfPoints, minX, maxX, minY, maxY);
        testAlgorithms(testUnit, bruteForceResult, myAlgorithmResult);
    }
}

void testWithTimeMeasurement(int numberOfTests) {
    std::vector<Point2D> testUnit;
    std::vector<int> time1, time2;
    MyAlgorithm alg;
    BruteForceAlgorithm brt;
    time_t clock;

    TestGenerator tg;

    for (int i = 1 ; i <= numberOfTests ; i++) {
        testUnit = tg.createTestVector(i);
        clock = time(NULL);
        alg.getMinRectangle(testUnit);
        clock = time(NULL) - clock;
        time1.push_back(clock);
        clock = time(NULL);
        brt.getMinRectangle(testUnit);
        clock = time(NULL) - clock;
        time2.push_back(clock);
    }
    showResultsInTable("Moj algorytm", "Brute force", time1, time2);
}

void UserInterface::mainMenu() {
    while(true) {
        showMainMenu();
        std::cout << "choice = ";
        char choice = std::cin.get();
        system("CLS");
        switch(choice) {
        case '1':
            testWithFileInput();
            break;
        case '2':
            testWithStandardInput();
            break;
        case '3':
            testWithRandomData();
            break;
        case '4':
            testWithTimeMeasurement(25);
            while(getchar() != '\n');
            break;
        default:
            return;
        }
    }
}
