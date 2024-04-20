

#ifndef EX07_TRAITS_POLICIES_VECTOR_POLICIES_H
#define EX07_TRAITS_POLICIES_VECTOR_POLICIES_H

#include "Vector.h"

template <typename T,template<typename> class CheckingPolicyT,template<typename> class InitPolicyT>
class IntervalPolicy : public CheckingPolicyT<T>, public InitPolicyT<T> {
    typedef CheckingPolicyT<T> CheckingPolicy;
    typedef InitPolicyT<T> InitPolicy;
};

template<typename T>
class NoCheckingPolicy{
    static void print(){
        std::cout<<"piesek"<<std::endl;
    }
    void check(T left, T right) {  }
};

template<typename T>
class ErrorCodeCheckingPolicy{
    static int errorCode;
    void check(T left, T right) { if(left>right) errorCode = -1; }
};


template<typename T>
class ExceptionCheckingPolicy{
    static int errorCode;
    void check(T left, T right) {
        if(left>right)
            throw std::runtime_error("Not correct interval bounds");
    }
};


struct NoInit{
    template<typename T>
    static void init(T & t){}
};

class ZeroInit{
    template<typename T>
    static void init(T & t){ t = T{}; }
};

template<typename T>
using NoCheckNoInit = IntervalPolicy<T,NoCheckingPolicy, NoInit>;

template <typename T>
using SafePolicy = IntervalPolicy<T,ExceptionCheckingPolicy,ZeroInit>;

#endif //EX07_TRAITS_POLICIES_VECTOR_POLICIES_H
