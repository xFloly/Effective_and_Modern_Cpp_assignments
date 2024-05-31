
#ifndef EX13_METAPROGRAMMING_POWER_H
#define EX13_METAPROGRAMMING_POWER_H

template<int x, int n>
struct Power{
  static constexpr long long value = Power<x,n-1>::value*x;
};

template<int x>
struct Power<x,0>{
  static constexpr int value = 1;
};

#endif //EX13_METAPROGRAMMING_POWER_H
