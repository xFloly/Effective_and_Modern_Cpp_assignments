

#ifndef EX07_TRAITS_POLICIES_VECTOR_POLICIES_H
#define EX07_TRAITS_POLICIES_VECTOR_POLICIES_H

#include "Vector.h"

template <typename CheckingPolicy, typename InitPolicy>
class IntervalPolicy : public CheckingPolicy, public InitPolicy {
public:

    using InitPolicy::init;
    using CheckingPolicy::check;
};


struct NoCheckingPolicy{
    static void check(std::size_t index, std::size_t size) {  }
};



struct ErrorCodeCheckingPolicy{
    static int errorCode;

    template<typename T>
    void check(T left, T right) { if(left>right) errorCode = -1; }
};



struct ExceptionCheckingPolicy{
    static int errorCode;


    static void check(std::size_t index, std::size_t size) {
        if(index >= size || index < 0)
            throw std::runtime_error("Not correct interval bounds");
    }
};


struct NoInit{
    template<typename T>
    static void init(T & t){}
};

struct ZeroInit{
    template<typename T>
    static void init(T & t){ t = T{}; }
};



using SafePolicy = IntervalPolicy<ExceptionCheckingPolicy,ZeroInit>;
using FastPolicy = IntervalPolicy<NoCheckingPolicy,NoInit>;
using InitFastPolicy = IntervalPolicy<NoCheckingPolicy,ZeroInit>;

#endif //EX07_TRAITS_POLICIES_VECTOR_POLICIES_H
