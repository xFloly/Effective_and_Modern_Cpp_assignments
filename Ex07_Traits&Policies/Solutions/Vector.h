
#ifndef LAB8_VECTOR_H
#define LAB8_VECTOR_H

#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <type_traits>
#include "vector_traits.h"
#include "vector_policies.h"

template <typename T,
        size_t N,
        template<typename,template<typename> class,template<typename> class> class IntervalPolicy = IntervalPolicy,
        template<typename> class InitPolicy = NoInit,
        template<typename> class CheckingPolicy = NoCheckingPolicy>
class Vector : public IntervalPolicy<T,InitPolicy, CheckingPolicy>{
  T data[N];

  //using IntervalPolicy<T,InitPolicy,CheckingPolicy>::CheckingPolicy;
  //using IntervalPolicy<T,InitPolicy,CheckingPolicy>::InitPolicy;

 public:
  typedef typename vector_traits<T>::value_type value_type;
  typedef typename std::size_t  size_type;
  typedef typename vector_traits<T>::pointer pointer;
  typedef typename vector_traits<T>::reference reference;
  typedef const typename vector_traits<T>::const_reference const_reference;
  typedef const typename  vector_traits<T>::access_type access_type;
  typedef typename vector_traits<T>::scalar_type scalar_type;


  Vector() = default;
  Vector(const Vector & v) = default;
  Vector &operator=(const Vector & m) = default;

  Vector(const std::initializer_list<T> &list){
	std::copy(list.begin(), list.end(), data);
  }

  size_type size() const {
	return N;
  }

  static T defaultValue(){
      if constexpr (is_string<T>::value){
          return "0";
      }
      return T();
  }

  access_type get(size_type index) const {
	return data[index];
  }

  void set(size_type index, access_type value) {
	data[index] = value;
  }

  friend Vector operator* (scalar_type x, const Vector & v ){
	Vector result;
    if constexpr (is_string<T>::value){
        for(int i=0; i < v.size(); ++i){
            auto val = v.get(i);
            for(auto j = 0; j < x; j++){
                val+=v.get(i);
            }
            result.set(i, val);
        }
    } else {
        for(int i=0; i < v.size(); ++i){
            result.set(i, x * v.get(i));
        }
    }
	return result;
  }

  friend std::ostream &operator<<(std::ostream &out, const Vector & v) {
	for(int i=0; i < v.size(); ++i){
	  out << v.get(i) << " ";
	}
	return out;
  }

  friend std::istream &operator>>(std::istream &in, Vector & v) {
	Vector::value_type value;
	for(int i=0; i < v.size(); ++i){
	  in >> value;
	  if(in)
		v.set(i, value);
	}
	return in;
  }

};

#endif // LAB8_VECTOR_H