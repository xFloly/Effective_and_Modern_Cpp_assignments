

#ifndef EX04_FUNCTIONTEMPLATES_TEMPLATES_H
#define EX04_FUNCTIONTEMPLATES_TEMPLATES_H

#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>

///Ex 01

template<typename T>
T sqr(T);

template<>
std::string sqr(std::string);

template<unsigned int N>
int mod(int,int);

template<typename T, typename Alloc, template<typename, typename> class Container>
void print(const Container<T,Alloc> &);

template<typename T, size_t N>
void print(const T(&)[N]);

template <typename C, typename F>
auto applyFun(const C&, F) -> C;

template <typename T,T(*f)(T),size_t N>
void process(T []);

///Ex 02

template<typename T>
int compare(T, T);


template<typename T>
int compare(T*, T*);

template<>
int compare(const char *, const char *);


///Ex 03
template<
        template<typename, typename> class OutContainer,
        typename T,
        typename Alloc,
        template<typename, typename> class InContainer,
        typename Predicate>
OutContainer<T,Alloc> selectIf(InContainer<T,Alloc> c, Predicate p);

#include "Templates_EX1.tpp"
#include "Templates_EX2.tpp"
#include "Templates_EX3.tpp"

#endif //EX04_FUNCTIONTEMPLATES_TEMPLATES_H
