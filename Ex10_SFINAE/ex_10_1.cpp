#include <iostream>
#include <vector>
#include "Solution/Ex1.h"

using namespace std;

int main(){
  cout << hasSize< int >::value << endl; // false
  cout << hasSize< vector<int> >::value << endl;//true
  cout << hasValueType< int >::value << endl; // false
  cout << hasValueType< vector<int> >::value << endl; //true

  std::vector<int> v{1,2,3,4,5};
  cout << v1::getSize(5) << endl; // 4
  cout << v1::getSize(v) << endl; // 20
  cout << v2::getSize(5) << endl; // 4
  cout << v2::getSize(v) << endl; // 20
  return 0;
}