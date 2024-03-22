#include "Templates.h"

template<typename T>
T sqr(T x){
    return x * x;
}

template<>
std::string sqr(std::string x){
    return x+x;
}

template<unsigned int N>
int mod(int a, int b){
    if (N != 0) {
        return (a+b) % N;
    }
    return a+b;
}

template<typename T, typename Alloc, template<typename, typename> class Container>
void print(const Container<T,Alloc> & container){
    for( auto x : container){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
}

template<typename T, size_t N>
void print(const T(&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename C, typename F>
auto applyFun(const C& c, F f) -> C{
    C result;
    std::transform(c.cbegin(), c.cend(), std::back_inserter(result), f);
    return result;
}

template <typename T,T(*f)(T),size_t N>
void process(T array[]){
    for (int i=0;i<N;i++) {
        array[i] = f(array[i]);
    }
}