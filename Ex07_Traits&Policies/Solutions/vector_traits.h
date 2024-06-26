
#ifndef EX07_TRAITS_POLICIES_VECTOR_TRAITS_H
#define EX07_TRAITS_POLICIES_VECTOR_TRAITS_H
#include "Vector.h"
#include <type_traits>
#include <string>
namespace emcpp {
  using std::string;

  template<typename T>
  struct vector_traits {
    typedef T value_type;
    typedef std::size_t size_type;
    typedef T *pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef const T &access_type;
    typedef T scalar_type;

    static T defaultValue() {
      return T();
    }

    static T mult(scalar_type a, value_type b) {
      T result = a * b;
      return result;
    }
  };

  template<>
  struct vector_traits<int> {
    typedef int value_type;
    typedef std::size_t size_type;
    typedef int *pointer;
    typedef int &reference;
    typedef int const_reference;
    typedef int access_type;
    typedef int scalar_type;

    static int defaultValue() {
      return int();
    }

    static int mult(scalar_type a, value_type b) {
      int result = a * b;
      return result;
    }
  };

  template<>
  struct vector_traits<double> {
    typedef double value_type;
    typedef std::size_t size_type;
    typedef double *pointer;
    typedef double &reference;
    typedef double const_reference;
    typedef double access_type;
    typedef double scalar_type;

    static double defaultValue() {
      return double();
    }

    static double mult(scalar_type a, value_type b) {
      double result = a * b;
      return result;
    }
  };

  template<>
  struct vector_traits<string> {
    typedef string value_type;
    typedef std::size_t size_type;
    typedef string *pointer;
    typedef string &reference;
    typedef const string &const_reference;
    typedef const string &access_type;
    typedef int scalar_type;

    static string defaultValue() {
      return "0";
    }

    static string mult(scalar_type a, value_type b) {
      string result = b;
      for (auto j = 0; j < a; j++) {
        result += b;
      }
      return result;
    }
  };

}
//template<typename T>
//struct is_string {
//    static constexpr bool value = false;
//};
//
//template<>
//struct is_string<string> {
//    static constexpr bool value = true;
//};

#endif //EX07_TRAITS_POLICIES_VECTOR_TRAITS_H
