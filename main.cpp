#include <iostream>
#include <vector>
#include "readMatrix.h"

int main(int argc, char* argv[]) {
    if (argc <= 1 || argc >= 4) {
        std::cerr << "Invalid number of arguments." << std::endl;
        exit(1);
    }

    size_t matrixSize;
    matrixSize = strtoul(argv[1], nullptr, 10);
    std::vector<std::vector<double>> matrix(matrixSize, std::vector<double> (matrixSize));
    if (matrixSize == 0) {
        std::cerr << "The first argument is not a positive integer." << std::endl;
        exit(1);
    }

    if (argc == 2) {
//        TODO create matrix by formula
    }
    else {
        readMatrix(argv[2], matrixSize, matrix);
    }

//    for (auto& it : matrix) {
//        for (double i : it)
//            std::cout << i << ' ';
//        std::cout << std::endl;
//    }

    return 0;
}
