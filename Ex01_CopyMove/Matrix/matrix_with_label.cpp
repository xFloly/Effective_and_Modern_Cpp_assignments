#include "matrix.h"

#include <utility>


using std::endl, std::string;


MatrixWithLabel::MatrixWithLabel(string label, int N, int M) : Matrix(N,M){
    this->label = std::move(label);
}

MatrixWithLabel::MatrixWithLabel(string label,std::initializer_list<std::initializer_list<double>> list) : Matrix(list){
    this->label = std::move(label);
}

MatrixWithLabel::MatrixWithLabel(const MatrixWithLabel& other) : Matrix(other){
    this->label = other.label;
}

MatrixWithLabel::MatrixWithLabel(MatrixWithLabel&& other)  noexcept : Matrix(std::move(other)){
    this->label = std::move(other.label);
}

MatrixWithLabel& MatrixWithLabel::operator=(MatrixWithLabel&& other) noexcept {
    Matrix::operator=(std::move(other));
    this->label = std::move(other.label);
    return *this;
}

string MatrixWithLabel::getLabel(){
    return this->label;
}

void MatrixWithLabel::setLabel(string newLabel){
    this->label = std::move(newLabel);
}