#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <algorithm>
#include<iterator>

using namespace std;


class Printer{
private:
    string prefix;
    string postfix;
    std::ostream& stream;
public:
    Printer(std::ostream& stream,string  prefix, string  postfix) : prefix(std::move(prefix)),postfix(std::move(postfix)),stream(stream){}

    template<typename T>
    void operator()(T obj){
        stream << prefix << obj << postfix;
    }



};

int main(){
  /// Creates unary functor that takes one argument x (of any type)
  /// and outputs to given stream x surrounded by given prefix na postfix
  /// e.g. in the following  [ x ]
  /// Hint: define function template.
  Printer printer(std::cout,  "[ ", " ] " );
  printer("hello");    // [ hello ]
  std::cout << "\nv = ";
  std::vector<int> v = {1, 2, 3, 4};
  std::for_each(v.begin(), v.end(), printer);  // v = [ 1 ] [ 2 ] [ 3 ] [ 4 ]

  std::ofstream file("Printer/myFile.txt");
  Printer filePrinter(file, "- ", "\n");
  filePrinter(5);
  filePrinter("My text");	
  return 0;
}
/** myFile.txt
- 5
- My text
*/
