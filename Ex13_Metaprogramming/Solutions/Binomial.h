
#ifndef EX13_METAPROGRAMMING_BINOMIAL_H
#define EX13_METAPROGRAMMING_BINOMIAL_H

#include <iostream>

template<int n, int k>
struct Binomial{
  static constexpr long long value = Binomial<n-1, k-1>::value + Binomial<n-1, k>::value;
};

template<int n>
struct Binomial<n,n>{
  static constexpr int value = 1;
};

template<int n>
struct Binomial<n,0>{
  static constexpr int value = 1;
};




#endif //EX13_METAPROGRAMMING_BINOMIAL_H
