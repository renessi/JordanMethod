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
    const size_t m = n;
    if (n == 0) {
        std::cerr << "The first argument is not a positive integer." << std::endl;
        exit(1);
    }

    std::vector<std::vector<double>> A(n, std::vector<double> (n));
    std::vector<double> rightAnswer(n), b(n), x(n);
    if (argc == 2) {
        createMatrixByFormula(A);
    }
    else {
        readMatrix(argv[2], A);
    }
    getRightAnswer(rightAnswer);
    fillInB(A, b, rightAnswer);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            std::cout << A[i][j] << ' ';
        std::cout << b[i] << std::endl;
    }

    size_t startTime = clock();
    bool matrixIsNonSingular = Jordan(n, A, b, x);
    size_t endTime = clock();

    if (!matrixIsNonSingular) {
        std::cout << "The matrix is singular." << std::endl;
    }
    else {
        std::cout << "p.6 Print result:" << std::endl;
        printResult(x, m);
        std::cout << "p.7 Norm of Ax - b: " << residualNorm(A, b, x) << std::endl;
        std::cout << "p.8 Norm of Error: " << normOfError(rightAnswer, x) << std::endl;
    }
    std::cout << "p.9 System solution time: " << endTime - startTime << std::endl;

    return 0;
}
