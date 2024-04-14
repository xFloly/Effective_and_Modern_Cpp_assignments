
#ifndef EX06_VARIADICTEMPLATE_MULTIVECTOR_H
#define EX06_VARIADICTEMPLATE_MULTIVECTOR_H

#include <iostream>
#include <vector>
#include <string>

template <typename S>
std::ostream& operator<<(std::ostream& os, const std::vector<S>& vector)
{
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}


template<typename... Types>
class MultiVector;

template<>
class MultiVector<>{
public:
    void push_back(){};
    void print(){
        std::cout<<std::endl;
    };
};


template<typename T, class ... R>
class MultiVector<T, R...> : public MultiVector<R...>{
private:
    std::vector<T> vec;
    MultiVector<R...> rest;
public:

    void push_back(const T& obj){
        vec.push_back(obj);
    };

    template<typename U>
    void push_back(const U& value) {
        rest.push_back(value);
    }

    void print(){
        std::cout<<"[ "<<vec<<" ]";
        rest.print();
    };

};


#endif //EX06_VARIADICTEMPLATE_MULTIVECTOR_H
