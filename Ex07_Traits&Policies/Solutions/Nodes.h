
#ifndef EX07_TRAITS_POLICIES_NODES_H
#define EX07_TRAITS_POLICIES_NODES_H

#include <iostream>
#include <memory>
#include <utility>

using namespace std;

template <int N>
class Vector{
  int data[N]{};

  template <typename, typename>
  friend class AddNode;
  template <typename>
  friend class MultNode;
  template <typename, typename>
  friend class MinNode;
public:
  Vector(){
    cout << " Default constr" << endl;
  }
  Vector(std::initializer_list<int> list){
    cout << " Init list constr" << endl;
    auto it = list.begin();
    for(int i=0; i<N; i++) {
      data[i] = *it++;
    }
  }
  Vector(const Vector & m){
    std::copy(m.data, m.data+N, data);
    cout << " Copy constr" << endl;
  }
  int operator[](int index) const {
    return data[index];
  }
  int & operator[](int index){
    return data[index];
  }

  friend ostream & operator << (ostream & out, const Vector & m){
    for(auto x : m.data){
      cout << x << ", ";
    }
    return out;
  }

  Vector &operator=(const Vector & v) = default;

  auto size() const {
    return N;
  }

  void set(int index, int value) {
    data[index] = value;
  }
};



template<typename L,typename R>
struct AddNode {
  const L & left;
  const R & right;

  auto operator[] (int i) const{
    return left[i]+right[i];
  }

  template<int N>
  operator Vector<N>(){
    Vector<N> v;
    for(int i=0; i<N; i++) {
      v.data[i] = this[i];
    }
    return v;
  }
};

template<typename L,typename R>
AddNode<L,R> operator+( L && l, R && r){
  return {std::forward<L>(l),std::forward<R>(r)};
}

template<typename R>
struct MultNode{
  const int & left;
  const R & right;

  auto operator[] (int i) const{
    return left*right[i];
  }

  template<int N>
  operator Vector<N>(){
    Vector<N> v;
    for(int i=0; i<N; i++) {
      v.data[i] = this[i];
    }
    return v;
  }
};

template<typename R>
MultNode<R> operator*( int && l, R && r){
  return {l,std::forward<R>(r)};
}

template<typename L,typename R>
struct MinNode{
  const L & left;
  const R & right;

  auto operator[] (int i) const{
    return left[i]-right[i];
  }

  template<int N>
  operator Vector<N>(){
    Vector<N> v;
    for(int i=0; i<N; i++) {
      v.data[i] = left[i]-right[i];
    }
    return v;
  }
};

template<typename L,typename R>
MinNode<L,R> operator-( L && l, R && r){
  return {std::forward<L>(l),std::forward<R>(r)};
}





#endif //EX07_TRAITS_POLICIES_NODES_H
