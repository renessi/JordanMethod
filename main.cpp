#include <iostream>
#include <vector>
#include <ctime>
#include "dataCreation.h"
#include "JordanMethod.h"

int main(int argc, char* argv[]) {
    if (argc <= 1 || argc >= 4) {
        std::cerr << "Invalid number of arguments." << std::endl;
        exit(1);
    }

    size_t n;
    n = strtoul(argv[1], nullptr, 10);
    std::vector<std::vector<double>> A(n, std::vector<double> (n));
    std::vector<double> rightAnswer(n), b(n), x(n);
    if (n == 0) {
        std::cerr << "The first argument is not a positive integer." << std::endl;
        exit(1);
    }

    if (argc == 2) {
        createMatrixByFormula(A);
    }
    else {
        readMatrix(argv[2], A);
    }
    getRightAnswer(rightAnswer);
    fillInB(A, b, rightAnswer);

    size_t startTime = clock();
    Jordan(n, A, b, x);
    size_t endTime = clock();

    std::cout << "p.6 Print result:" << std::endl;
    printResult(x, n);
    std::cout << "p.7 Norm of Ax - b: " << residualNorm(A, b, x) << std::endl;
    std::cout << "p.8 Norm of Error: " << normOfError(rightAnswer, x) << std::endl;
    std::cout << "p.9 System solution time: " << endTime - startTime << std::endl;

//    for (auto& it : A) {
//        for (double i : it)
//            std::cout << i << ' ';
//        std::cout << std::endl;
//    }
//    for (double i : x)
//        std::cout << i << ' ';
//    std::cout << std::endl;

    return 0;
}
