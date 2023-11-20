#ifndef JORDANMETHOD_DATACREATION_H
#define JORDANMETHOD_DATACREATION_H

#include <iostream>
#include <vector>

void readMatrix(const char* fileName, std::vector<std::vector<double>>& A);

void createMatrixByFormula(std::vector<std::vector<double>>& A);

void getRightAnswer(std::vector<double>& rightAnswer);

void fillInB(const std::vector<std::vector<double>>& A, std::vector<double>& b,
             const std::vector<double>& rightAnswer);

#endif //JORDANMETHOD_DATACREATION_H
