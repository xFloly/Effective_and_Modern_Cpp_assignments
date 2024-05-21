
#ifndef EX11_CONCEPTS_FILESYSTEM_REGEX_CONCEPTSCONTAINER_H
#define EX11_CONCEPTS_FILESYSTEM_REGEX_CONCEPTSCONTAINER_H

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

template<typename T>
concept Printable = requires(T obj){
  obj.print();
};

template<typename T>
concept OutStream = requires(T obj) {
  std::cout << obj;
};

template<typename T>
concept Container = requires(T obj){
  typename T::value_type;
  { *std::begin(obj) } -> std::same_as<typename T::value_type&>;
  { *std::end(obj) };
  { *std::begin(obj) + *std::begin(obj) } -> std::same_as<typename T::value_type>;
};

using namespace std;
template <typename  T>
class A{
protected:
  T x;
public:
  A(T x = T()) : x(x) {}
  void print() const{
    cout << "[" << x << "]";
  }
  friend A operator+(const A & a, const A & b){
    return a.x + b.x;
  }

};

template <typename T>
class B: public A<T>{
public:
  using A<T>::A;
  B(const A<T>& a) : A<T>(a.x) {}

  friend std::ostream & operator<<(std::ostream & out, const B & b){
    return (out << "#" << b.x << "#");
  }

  friend B operator+(const B & a, const B & b){
    return a.x + b.x;
  }
};

template<typename T>
void print(const T& obj) {
  if constexpr(OutStream<T>) {
    std::cout << obj;
  }
  else if constexpr(Printable<T>) {
    obj.print();
  }
  cout << endl;
}

template<Container C>
void print(const C& container){
  int i{};
  for (const auto& element : container) {
    cout << i++ << " : ";
    print(element);
  }
  cout << "---------\n";
}

template<typename T>
auto sum(const T& vec) {
  typename T::value_type x{};
  return accumulate(vec.begin(), vec.end(), x);
}
#endif //EX11_CONCEPTS_FILESYSTEM_REGEX_CONCEPTSCONTAINER_H
