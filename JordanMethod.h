#ifndef JORDANMETHOD_JORDANMETHOD_H
#define JORDANMETHOD_JORDANMETHOD_H

bool Jordan(size_t n, std::vector<std::vector<double>>& A,
             std::vector<double>& b, std::vector<double>& x);

void printResult(const std::vector<double>& x, size_t m);

double residualNorm(const std::vector<std::vector<double>>& A, const std::vector<double>& b,
                  const std::vector<double>& x);

double normOfError(const std::vector<double>& rightAnswer, const std::vector<double>& x);

#endif //JORDANMETHOD_JORDANMETHOD_H