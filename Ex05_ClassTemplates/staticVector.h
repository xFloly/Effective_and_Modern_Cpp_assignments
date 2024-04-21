
#ifndef STATIC_VECTOR_H
#define STATIC_VECTOR_H


#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>


template <typename T, size_t N = 0>
class Vector{
    T data[N];

    template<typename, size_t>
    friend class Vector;
public:
    typedef T value_type;
    typedef std::size_t  size_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T& const_reference;

    Vector() {
        std::fill(data, data+N,0);
    }

    Vector(const Vector<T,N> & v) = default;

    explicit Vector(const Vector<T,0> & v){
        std::copy(v.data.get(),v.data.get()+N,data);
    }

    template<typename S, size_t M>
    explicit Vector(const Vector<S,M> & v){
        auto min = std::min(v.size(),N);
        for(auto i = 0; i < min ;i++){
            data[i] = static_cast<T>(v[i]);
        }
        for(auto i = min; i < N; i++){
            data[i] = 0;
        }
    }


    Vector &operator=(const Vector & m)
    {
        if(this != &m){
            std::copy(m.data, m.data + N, data);
        }
        return *this;
    }

    Vector(const std::initializer_list<T> &list) {

        std::copy(list.begin(), list.end(), data);
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
        for( auto elem: v.data ){
            out << elem << " ";
        }
        return out;
    }

    friend Vector operator+ (const Vector<T,N> & u, const Vector<T,N> & v ){
        Vector<T,N> newVector{};
        std::transform(u.data, u.data + N, v.data, newVector.data,
                       [](const T& a, const T& b) -> T { return a + b; });
        return newVector;
    }
};

#endif //STATIC_VECTOR_H