

#ifndef EX07_TRAITS_POLICIES_VECTOR_POLICIES_H
#define EX07_TRAITS_POLICIES_VECTOR_POLICIES_H

#include "Vector.h"

template <typename T, template<typename> class CheckingPolicy, template<typename> class InitPolicy>
class IntervalPolicy : public CheckingPolicy<T>, public InitPolicy<T> {
public:
    using InitPolicy<T>::init;

};

template<typename T>
struct NoCheckingPolicy{


    void check(T left, T right) {  }


};


template<typename T>
struct ErrorCodeCheckingPolicy{
    static int errorCode;

    void check(T left, T right) { if(left>right) errorCode = -1; }
};


template<typename T>
struct ExceptionCheckingPolicy{
    static int errorCode;


    void check(T left, T right) {
        if(left>right)
            throw std::runtime_error("Not correct interval bounds");
    }
};

template<typename T>
struct NoInit{

    static void init(T & t){}
};

template<typename T>
struct ZeroInit{
    static void init(T & t){ t = T{}; }
};

template<typename T>
using SafePolicy = IntervalPolicy<T,ExceptionCheckingPolicy,ZeroInit>;

#endif //EX07_TRAITS_POLICIES_VECTOR_POLICIES_H
