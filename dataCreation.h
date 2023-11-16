#ifndef JORDANMETHOD_DATACREATION_H
#define JORDANMETHOD_DATACREATION_H

void readMatrix(const char* fileName, std::vector<std::vector<double>>& matrix);

void createMatrixByFormula(std::vector<std::vector<double>>& matrix);

void getRightAnswer(std::vector<double>& rightAnswer);

void fillInB(const std::vector<std::vector<double>>& matrix, std::vector<double>& b,
             const std::vector<double>& rightAnswer);

#endif //JORDANMETHOD_DATACREATION_H
