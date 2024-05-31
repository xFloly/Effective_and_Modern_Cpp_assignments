
#ifndef EX13_METAPROGRAMMING_PASCALSTRIANGLE_H
#define EX13_METAPROGRAMMING_PASCALSTRIANGLE_H
/**
 *  Exercise 2b:
 * Implement function generate_triangle that during compilation
 * generates the Pascal trriangle of the given size N.
 * Pascal triangle
 * https://en.wikipedia.org/wiki/Pascal%27s_triangle
 *
 */
#include <array>
#include <iostream>
#include <cmath>

template <size_t N>
class PascalTriangle{
private:
  std::array<std::array<int, N>, N> triangle;
public:
  constexpr PascalTriangle() : triangle{} {
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = 0; j <= i; ++j) {
        if (j == 0 || j == i) {
          triangle[i][j] = 1;
        } else {
          triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
      }
    }
  }
  constexpr int operator()(size_t n, size_t m) const {
    return triangle[n][m];
  }

};

template <auto N>
constexpr PascalTriangle<N> generatePascalTriangle(){
  return PascalTriangle<N>();
}




#endif //EX13_METAPROGRAMMING_PASCALSTRIANGLE_H
