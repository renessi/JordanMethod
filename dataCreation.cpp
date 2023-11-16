#include <iostream>
#include <fstream>
#include <vector>
#include "dataCreation.h"

double formulaToCreateMatrix(size_t i, size_t j) {
    return (double) (i + j);
}

void readMatrix(const char* fileName, std::vector<std::vector<double>>& matrix) {
    std::ifstream input(fileName);

    if (input.is_open()) {
        for (std::vector<double>& row : matrix) {
            for (double& cell : row) {
                if (!(input >> cell)) {
                    std::cerr << "Can not read from file." << fileName << std::endl;
                    input.close();
                    exit(1);
                }
            }
        }
        if (!input.eof()) {
            std::cerr << "The file contains unnecessary data." << fileName << std::endl;
            input.close();
            exit(1);
        }
        input.close();
    }
    else {
        std::cerr << "Can not open file." << fileName << std::endl;
        exit(1);
    }
}

void createMatrixByFormula(std::vector<std::vector<double>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] = formulaToCreateMatrix(i, j);
        }
    }
}

void getRightAnswer(std::vector<double>& rightAnswer) {
    for (size_t i = 0; i < rightAnswer.size(); ++i) {
        rightAnswer[i] = i % 2 ? 0. : 1.;
    }
}

void fillInB(const std::vector<std::vector<double>>& matrix, std::vector<double>& b,
             const std::vector<double>& rightAnswer) {
    for (size_t i = 0; i < b.size(); ++i) {
        b[i] = 0.;
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            b[i] += matrix[i][j] * rightAnswer[j];
        }
    }
}