
#ifndef EX06_VARIADICTEMPLATE_FUNCTIONS_H
#define EX06_VARIADICTEMPLATE_FUNCTIONS_H


template<class ...Ts>
double average(Ts&& ... args){
    const std::size_t n = sizeof...(Ts);
    return double((args + ...)) / n;
}

template<typename F, class ...Ts>
auto computeSum(F&& f, Ts&&... args) {
    return (f(args) + ...);
}

template<template<typename, typename> class Container,
        typename T,
        typename Alloc,
        class ... Ts>
void insert(Container<T,Alloc> & container, Ts&&... args) {
    (container.push_back(args),...);
}

#endif //EX06_VARIADICTEMPLATE_FUNCTIONS_H
