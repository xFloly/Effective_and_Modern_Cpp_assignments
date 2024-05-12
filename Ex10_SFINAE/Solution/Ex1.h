
#ifndef EX10_SFINAE_EX1_H
#define EX10_SFINAE_EX1_H
#include <iostream>
#include <type_traits>

template <typename... Ts>
using void_t = void;

template <typename T, typename = void>
struct hasValueType : std::false_type {};

template <typename T>
struct hasValueType<T, void_t<typename T::value_type>>
    : std::true_type {};

template <typename T, typename = void>
struct hasSize : std::false_type {};

template <typename T>
struct hasSize<T, void_t<decltype(std::declval<T>().size()) >>
    : std::true_type {};

template <typename T>
inline constexpr bool hasSize_v = hasSize<T>::value;

template <typename T>
inline constexpr bool hasValueType_v = hasValueType<T>::value;

namespace v1{
  template<typename T>
  size_t getSize(const T & x,std::enable_if_t< hasValueType_v<T> && hasSize_v<T>, int> = 0){
    return x.size() * sizeof(typename T::value_type);
  }

  template<typename T>
  size_t getSize(const T & x,std::enable_if_t< !(hasValueType_v<T> && hasSize_v<T>), int> = 0){
    return sizeof(T);

  }
}

namespace v2{
  template<typename T>
  size_t getSize(const T & x){
    if constexpr (hasValueType_v<T> && hasSize_v<T>){
      return x.size() * sizeof(typename T::value_type);
    } else {
      return sizeof(T);
    };

  }
}
#endif //EX10_SFINAE_EX1_H
