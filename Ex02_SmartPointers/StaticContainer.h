#include <iostream>
#include "Box.h"

using namespace std;

// Exercise: modify code so that appropriate constructor and operators are called.
class Container : public Box {
 public:
    static bool verbose;
    Container(int content):Box(content){}
    Container(const Container & container): Box(container){
        if(verbose) cout << "Container: copy constructor.\n";
    }
    Container & operator=(const Container &container){
        Box::operator=(container);
	    if(verbose) cout << "Container: copy assignment.\n";
		return *this;
    }
  	Container(Container && container) : Box(std::move(container)){
		if(verbose) cout << "Container: move constructor.\n";
  	}
  	Container & operator=(Container && container){
        Box::operator=(std::move(container));
		if(verbose) cout << "Container: move assignment.\n";
		return *this;
  	}
    ~Container(){
        if(verbose) cout << "Container destructor. \n";
        //Box::~Box();
    }
    friend Container operator+(const Container & p1, const Container & p2);
    friend ostream & operator << (ostream & out, const Container & p){
        return (cout << " [" << p.getContent() << "] ");
    }
};
bool Container::verbose = false;

inline Container operator+(const Container & p1, const Container & p2){
    Container suma(p1.getContent() + p2.getContent());
    return suma;
}