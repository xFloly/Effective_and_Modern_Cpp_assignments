
#include <array>
#include <iostream>
#include <cmath>
#include "Solutions/PascalsTriangle.h"

/** 
 * Exercise 2a: 
 * Implement function power that computes x^n 
 * during compilation using recurrent formula
   x^2n = (x^n)^2
   x^2n+1 = (x^2n)*x
  */
consteval auto power(auto x, int n) {
  if(n==0){
    return 1;
  }
  if (n%2==0){
    auto x2 = power(x,n/2);
    return x2*x2;
  } else {
    return x * power(x,n-1);
  }
}

constinit double fiveToPowerFour = power(5, 4);

constexpr size_t n = 10;
constexpr auto triangle = generatePascalTriangle<n>();


int main(){
  static_assert(triangle(0,0) == 1);
  static_assert(triangle(5,3) == 10);
  static_assert(triangle(9,4) == 126);

}
