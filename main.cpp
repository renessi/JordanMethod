#include <iostream>
#include <vector>
#include "dataCreation.h"

int main(int argc, char* argv[]) {
    if (argc <= 1 || argc >= 4) {
        std::cerr << "Invalid number of arguments." << std::endl;
        exit(1);
    }

    size_t matrixSize;
    matrixSize = strtoul(argv[1], nullptr, 10);
    std::vector<std::vector<double>> matrix(matrixSize, std::vector<double> (matrixSize));
    std::vector<double> rightAnswer(matrixSize), b(matrixSize);
    if (matrixSize == 0) {
        std::cerr << "The first argument is not a positive integer." << std::endl;
        exit(1);
    }

    if (argc == 2) {
        createMatrixByFormula(matrix);
    }
    else {
        readMatrix(argv[2], matrix);
    }
    getRightAnswer(rightAnswer);
    fillInB(matrix, b, rightAnswer);

//    for (auto& it : matrix) {
//        for (double i : it)
//            std::cout << i << ' ';
//        std::cout << std::endl;
//    }
//    for (double i : b)
//        std::cout << i << ' ';
//    std::cout << std::endl;

    return 0;
}
