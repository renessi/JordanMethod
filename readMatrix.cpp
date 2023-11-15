#include <iostream>
#include <fstream>
#include <vector>
#include "readMatrix.h"

void readMatrix(const char* fileName, const size_t matrixSize,
                std::vector<std::vector<double>>& matrix) {
    std::ifstream input(fileName);

    if (input.is_open()) {
        for (size_t i = 0; i < matrixSize; ++i) {
            for (size_t j = 0; j < matrixSize; ++j) {
                if (!(input >> matrix[i][j])) {
                    std::cerr << "Can not read from file " << fileName << std::endl;
                    input.close();
                    exit(1);
                }
            }
        }
        input.close();
    }
    else {
        std::cerr << "Can not open file " << fileName << std::endl;
        exit(1);
    }
}