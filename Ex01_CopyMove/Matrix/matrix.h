#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <initializer_list>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using ulonglong = unsigned long long;

class Matrix {
public:
    Matrix();
    Matrix(ulonglong, ulonglong);
    Matrix(std::initializer_list<std::initializer_list<double>>);
    Matrix(const Matrix&);
    Matrix(Matrix&&) noexcept;

    ~Matrix();

    Matrix& operator=(const Matrix&);
    Matrix& operator=(Matrix&&) noexcept;

    double& operator()(ulonglong, ulonglong);
    const double& operator()(ulonglong, ulonglong) const;

    Matrix operator-() const;

    friend std::ostream& operator<<(std::ostream&, const Matrix&);

private:
    double* data;
    ulonglong N;
    ulonglong M;

    [[nodiscard]] std::string sizeOfMatrixName() const;
};

class MatrixWithLabel : Matrix{
public:
    using Matrix::Matrix;
    MatrixWithLabel(std::string, int, int);
    MatrixWithLabel(std::string,std::initializer_list<std::initializer_list<double>>);

    std::string getLabel();
    void setLabel(std::string);

private:
    std::string label;

};

#endif //MATRIX_MATRIX_H
