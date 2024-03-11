#include "matrix.h"

using std::endl;

#define EPS 1e-10

Matrix::Matrix(): N(0), M(0), data(nullptr) {
    std::cout << " default constructor of" << sizeOfMatrixName() << endl;
}

Matrix::Matrix(ulonglong N, ulonglong M): N(N), M(M) {
    std::cout << " parameter constructor of" << sizeOfMatrixName() << endl;

    this->data = new double[N * M]{};
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list) : N(list.size()), M(0) {
    for (const auto& row : list) {
        if (row.size() > M) M = row.size();
    }

    std::cout << " initializer list constructor of" << sizeOfMatrixName() << std::endl;

    this->data = new double[N * M]{};

    int i = 0;
    for (const auto& row : list) {
        int j = 0;
        for (double val : row) {
            data[i * M + j] = val;
            ++j;
        }
        ++i;
    }
}

Matrix::Matrix(const Matrix& other) : N(other.N), M(other.M) {
    std::cout << " copy constructor of" << sizeOfMatrixName() << std::endl;

    this->data = new double[N * M]{};

    std::copy(other.data, other.data + N * M, this->data);
}

Matrix::Matrix(Matrix&& other)  noexcept : N(other.N), M(other.M) {
    std::cout << " move constructor of" << sizeOfMatrixName() << std::endl;

    this->data = other.data;

    other.M = 0;
    other.N = 0;
    other.data = nullptr;
}

Matrix::~Matrix() {
    delete[] data;
}

Matrix& Matrix::operator=(const Matrix& other) {
    std::cout << " copy assignment of" << sizeOfMatrixName() << std::endl;

    if (this != &other) {

        delete[] data;

        N = other.N;
        M = other.M;
        data = new double[N * M]{};

        std::copy(other.data, other.data + N * M, data);
    }

    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept{
    std::cout << " move assignment of" << sizeOfMatrixName() << std::endl;

    if (this != &other) {

        delete[] data;

        this->data = other.data;
        this->M = other.M;
        this->N =other.N;

        other.M = 0;
        other.N = 0;
        other.data = nullptr;
    }

    return *this;
}

double& Matrix::operator()(ulonglong i, ulonglong j) {
    if (i >= N || j >= M) {
        throw std::out_of_range("Index out of range");
    }
    return data[(i-1) * M + (j-1)];
}

const double& Matrix::operator()(ulonglong i, ulonglong j) const {
    if (i >= N || j >= M) {
        throw std::out_of_range("Index out of range");
    }
    return data[(i-1) * M + (j-1)];
}

Matrix Matrix::operator-() const {
    Matrix result(N,M);
    std::copy(this->data,this->data + N * M, result.data);
    std::for_each(result.data, result.data+ N * M, [](double& d){
        if(d > EPS || d < -EPS) d = -d;
    });
    return result;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {

    for (int i = 0; i < m.N; ++i) {
        os << "{ ";
        for(int j = 0; j < m.M;j++) {
            os << m.data[i*m.M+j] << " ";
        }
        os << "}" << endl;
    }

    return os;
}

std::string Matrix::sizeOfMatrixName() const {
    std::stringstream ss;
    ss << " " << N << "x" << M << " Matrix";
    return ss.str();
}
