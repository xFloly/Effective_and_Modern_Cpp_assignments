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

Matrix::Matrix(const Matrix& m) : N(m.N), M(m.M) {
    std::cout << " copy constructor of" << sizeOfMatrixName() << std::endl;

    this->data = new double[N * M]{};

    std::copy(m.data, m.data + N * M, data);
}

Matrix::Matrix(Matrix&& m)  noexcept : N(m.N), M(m.M) {
    std::cout << " move constructor of" << sizeOfMatrixName() << std::endl;

    this->data = m.data;

    m.M = 0;
    m.N = 0;
    m.data = nullptr;
}

Matrix::~Matrix() {
    delete[] data;
}

Matrix& Matrix::operator=(const Matrix& m) {
    std::cout << " copy assignment of" << sizeOfMatrixName() << std::endl;

    if (this == &m) {
        return *this;
    }

    delete[] data;

    N = m.N;
    M = m.M;
    data = new double[N * M]{};

    std::copy(m.data, m.data + N * M, data);

    return *this;
}

Matrix& Matrix::operator=(Matrix&& m) noexcept{
    std::cout << " move assignment of" << sizeOfMatrixName() << std::endl;

    if (this == &m) {
        return *this;
    }

    this->data = m.data;
    this->M = m.M;
    this->N =m.N;

    m.M = 0;
    m.N = 0;
    m.data = nullptr;

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
