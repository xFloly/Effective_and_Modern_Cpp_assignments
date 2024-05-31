#ifndef EX13_METAPROGRAMMING_INTEGERLIST_H
#define EX13_METAPROGRAMMING_INTEGERLIST_H

#include <type_traits>
#include <iostream>
#include <iomanip>

template <int... Ints>
struct IntegerList;

template<int Int>
struct IntegerList<Int>{
  static constexpr int max(){
    return Int;
  }

  static constexpr int get(size_t){
    return Int;
  }
};

template<int Int, int... Ints>
struct IntegerList<Int,Ints...>{
  static constexpr int max(){
    return std::max(Int,IntegerList<Ints...>::max());
  }

  static constexpr int get(size_t t){
    if(t==0) {
      return Int;
    }
    return IntegerList<Ints...>::get(t-1);
  }


};
template<int... Ints>
std::ostream& operator<<(std::ostream& out, const IntegerList<Ints...>& v){
  ((out<<Ints<<" "), ...);
  out<<std::endl;
  return out;
}

template<size_t v, typename List>
struct getInt{
  static constexpr int value = List::get(v);
};


template<typename List>
struct Max {
  static constexpr int value = List::max();
};

template <typename IntList>
struct IsSorted;

template <int... Ints>
struct IsSorted<IntegerList<Ints...>> {
  using List = IntegerList<Ints...>;

  static constexpr bool _value() {
    bool res = true;
    for (size_t i = 0; i < sizeof...(Ints) - 1; ++i) {
      res &= List::get(i) < List::get(i + 1);
    }
    return res;
  }

  static constexpr bool value = _value();
};

template<typename List1, typename List2>
struct Join;

template<int... Ints1, int... Ints2>
struct Join<IntegerList<Ints1...>, IntegerList<Ints2...>> {
  using type = IntegerList<Ints1..., Ints2...>;
};


#endif //EX13_METAPROGRAMMING_INTEGERLIST_H
