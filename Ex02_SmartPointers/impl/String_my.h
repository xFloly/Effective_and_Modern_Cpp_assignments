#include <iostream>
#include <algorithm>
#include <memory>
#include "MyString.h"
using namespace std;

class String{
   using string = std::shared_ptr<emcpp::MyString>;
//    using string = std::string;
/// Store a pointer to dynamically allocated string!
    string pstring;
public:
    String();     /// creates an empty string
    explicit String(const char * str);           /// copy C-string
    String(const String & ) = default;            /// no copy
    String& operator=(const String & s); /// no copy
    /// makes a copy of a string if it has more than one reference.
    void set(int index, char ch);
    /// no copy
    [[nodiscard]] char get(int index) const;
    /// creates a new string only if both strings are non empty
    friend String operator+(String a, String b);
    friend std::ostream & operator<< (std::ostream & out, const String& s);

  size_t use_count() const {
    return pstring.use_count();
  }

  const emcpp::MyString* get_raw_ptr() const {
    return pstring.get();
  }
};
