
#ifndef EX05_CLASSTEMPLATES_DYNAMICVECTO_H
#define EX05_CLASSTEMPLATES_DYNAMICVECTO_H


#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>
#include "staticVector.h"

class VectorException : public std::runtime_error {
public:
    VectorException() : std::runtime_error("incompatible sizes in Vector::operator+") { }
};

template <typename T>
class Vector<T,0>{
    std::unique_ptr<T[]> data;
    size_t N;

    template<typename, size_t>
    friend class Vector;
public:
    typedef T value_type;
    typedef std::size_t  size_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T& const_reference;

    explicit Vector(int size) : N(size) {
        data = std::make_unique<T[]>(N);
    }

    Vector(const Vector<T,0> & v) : N(v.N){
        data = std::make_unique<T[]>(N);
        std::copy(v.data.get(), v.data.get() + N, data.get());
    }

    template<typename S, size_t M>
    explicit Vector(const Vector<S,M> & v) : N(M){
        data = std::make_unique<T[]>(N);
        std::copy(v.data.get(), v.data.get() + N, data.get());
    }

    template<size_t M>
    explicit Vector(const Vector<T,M> & v) : N(v.size()){
        data = std::make_unique<T[]>(N);
        std::copy(v.data, v.data + N, data.get());
    }


    Vector &operator=(const Vector & m){
        if(this != &m){
            N = m.N;
            data = std::make_unique<T[]>(N);
            std::copy(m.data.get(), m.data.get() + N, data.get());
        }
        return *this;
    }

    Vector(const std::initializer_list<T> &list) : N(list.size()){
        data = std::make_unique<T[]>(N);

        std::copy(list.begin(), list.end(), data.get());
    }

    friend Vector operator+ (const  Vector & u, const Vector<T,0> & v ) {
        if( u.size() != v.size()) throw VectorException();

        Vector<T, 0> newVector(u.N);
        std::transform(u.data.get(), u.data.get() + u.N, v.data.get(), newVector.data.get(),
                       [](const T &a, const T &b) -> T { return a + b; });
        return newVector;
    }

    constexpr size_type size() const {
        return N;
    }

    const_reference get(size_type index) const {
        return data[index];
    }

    void set(size_type index, const_reference value) {
        data[index] = value;
    }

    reference operator[](size_type index){
        return data[index];
    }

    const_reference operator[](size_type index) const{
        return data[index];
    }

    friend std::ostream &operator<<(std::ostream &out, const Vector & v) {
        for (size_t i = 0; i < v.N; ++i) {
            out << v.data[i] << " ";
        }
        return out;
    }

    void resize(int new_size){
        if (new_size != N){
            N = new_size;
            auto new_data = std::make_unique<T[]>(N);
            std::copy(data.get(), data.get() + N, new_data.get());
        }
    }

};


#endif //EX05_CLASSTEMPLATES_DYNAMICVECTO_H
