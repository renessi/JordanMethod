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

// return false if A is singular
bool findMainElement(std::vector<std::vector<double>> &A, size_t& x, size_t& y, size_t k,
                     size_t* rowInd, size_t* colInd, size_t n) {
    // if the absolute value of the main element of the matrix is less than EPS,
    // we consider that the matrix is singular
    const double EPS = 1e-10;

    x = y = k;

    for (size_t i = k; i < n; ++i) {
        for (size_t j = k; j < n; ++j) {
            if (std::abs(A[rowInd[i]][colInd[j]]) > std::abs(A[rowInd[x]][colInd[y]])) {
                x = i;
                y = j;
            }
        }
    }

    return std::abs(A[rowInd[x]][colInd[y]]) > EPS;
}

bool Jordan(const size_t n, std::vector<std::vector<double>>& A,
            std::vector<double>& b, std::vector<double>& x) {
    size_t rowInd[n], colInd[n];
    for (size_t i = 0; i < n; ++i) {
        rowInd[i] = colInd[i] = i;
    }

    for (size_t k = 0; k < n; ++k) {
        size_t row, column;
        if (!findMainElement(A, row, column, k, rowInd, colInd, n)) {
            return false;
        }
//        std::cout << "! " << rowInd[k] << ' ' << rowInd[row] << std::endl;
//        std::cout << "! " << colInd[k] << ' ' << colInd[column] << std::endl;
        std::swap(rowInd[k], rowInd[row]);
        std::swap(colInd[k], colInd[column]);

        double mainElement = A[rowInd[k]][colInd[k]];

//        auto foo = [&]() {
//            std::cout << "Main: " << mainElement << std::endl;
//            for (row = 0; row < n; ++row) {
//                for (column = 0; column < n; ++column)
//                    std::cout << A[rowInd[row]][colInd[column]] << ' ';
//                std::cout << b[colInd[row]] << std::endl;
//            }
//        };
//        foo();

        for (size_t j = k; j < n; ++j) {
            A[rowInd[k]][colInd[j]] /= mainElement;
        }
        b[rowInd[k]] /= mainElement;

//        foo();

        for (size_t i = 0; i < n; ++i) {
            if (i == k) {
                continue;
            }

            const double Aik = A[rowInd[i]][colInd[k]];

            for (size_t j = k; j < n; ++j) {
                A[rowInd[i]][colInd[j]] -= Aik * A[rowInd[k]][colInd[j]];
            }
            b[rowInd[i]] -= Aik * b[rowInd[k]];
        }

//        foo();
    }

    for (size_t i = 0; i < n; ++i) {
        x[colInd[i]] = b[rowInd[i]];
    }
//    for (size_t i = 0; i < n; ++i)
//        std::cout << rowInd[i] << ' ' << colInd[i] << std::endl;

    return true;
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