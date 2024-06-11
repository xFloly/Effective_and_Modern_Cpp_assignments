#include "String_my.h"

bool emcpp::MyString::logging = true;

String::String() : pstring(std::make_shared<emcpp::MyString>()) {
    //std::cout << "String: Default constructor" << std::endl;
}

String::String(const char* c_str) : pstring(std::make_shared<emcpp::MyString>(c_str)) {
    //std::cout << "String: Constructor from C string" << std::endl;
}

//String::String(const String & other) : pstring(other.pstring){
//    //std::cout << "String: Copy constructor" << std::endl;
//}

String& String::operator=(const String & s){
    if (this != &s) {
        pstring = s.pstring;
    }
    return *this;
}

void String::set(int index, char ch){
    if(pstring.unique()){
        (*pstring)[index]=ch;
    } else {
        pstring = std::make_shared<emcpp::MyString>(*pstring);
        (*pstring)[index]=ch;
    }
}

char String::get(int index) const{
    return (*pstring)[index];
}

String operator+(String a, String b){
    if(a.pstring->empty()){
        return String{a};
    }
    if(b.pstring->empty()){
        return String{b};
    }

    std::string str = *a.pstring + *b.pstring;
    const char* charArray = str.c_str();

    return String (charArray);
}
std::ostream & operator<< (std::ostream & out, const String& s){
    out << *s.pstring;
    return out;
}
