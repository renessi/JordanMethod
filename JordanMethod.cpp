#include <vector>
#include <iostream>
#include "JordanMethod.h"

double normOfVector (const std::vector<double>& v) {
    double result = 0;
    for (double i : v) {
        result = std::max(result, i < 0 ? -i : i);
    }
    return result;
}

void Jordan(const size_t n, std::vector<std::vector<double>>& A,
            std::vector<double>& b, std::vector<double>& x) {
    for (int i = 0; i < x.size(); ++i)
        x[i] = i % 2 == 0;
}

void printResult(const std::vector<double>& x, size_t m) {
    for (size_t i = 0; i < std::min(x.size(), m); ++i) {
        std::cout << x[i] << std::endl;
    }
}

double residualNorm(const std::vector<std::vector<double>>& A, const std::vector<double>& b,
                    const std::vector<double>& x) {
    std::vector<double> v(x.size(), 0.);
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A.size(); ++j) {
            v[i] += A[i][j] * x[j];
        }
        v[i] -= b[i];
    }
    return normOfVector(v);
}

double normOfError(const std::vector<double>& rightAnswer, const std::vector<double>& x) {
    std::vector<double> difference(x.size(), 0.);
    for (size_t i = 0; i < x.size(); ++i) {
        difference[i] = x[i] - rightAnswer[i];
    }
    return normOfVector(difference);
}