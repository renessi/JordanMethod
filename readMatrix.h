#ifndef JORDANMETHOD_READMATRIX_H
#define JORDANMETHOD_READMATRIX_H

#include <fstream>

void readMatrix(char* fileName, const size_t matrixSize,
                std::vector<std::vector<double>>& matrix) {
    std::ifstream input(fileName);

    if (input.is_open()) {
        double cur;
        for (size_t i = 0; i < matrixSize; ++i) {
            for (size_t j = 0; j < matrixSize; ++j) {
                input >> cur;
                matrix[i][j] = cur;
            }
        }
        input.close();
    }
    else {
        std::cerr << "Can not open file " << fileName << std::endl;
        exit(1);
    }
}

#endif //JORDANMETHOD_READMATRIX_H
