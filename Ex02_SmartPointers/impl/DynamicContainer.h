#pragma once
#include <iostream>
#include <memory>
#include "Box.h"

using std::cout, std::endl;

class Container{
    // Exercise 2: Use smart pointer.
    std::unique_ptr<Box> pbox;
public:
    static bool verbose;
    explicit Container(int content): pbox(std::make_unique<Box>(content)){
        if(verbose) cout << "Creating Container" << endl;
        pbox->setContent(content);
    }

    Container(const Container & container): pbox(std::make_unique<Box>(*(container.pbox))){
        if(verbose) cout << "Creating copy of Container\n";
    }

    Container(Container&& container) noexcept :  pbox(std::move(container.pbox)){
        if(verbose) cout << "Move constructor of Container\n";
    }

    Container & operator=(const Container &container){
        if(this != &container) {
            if(verbose) cout << "Copying Container\n";
            this->pbox->setContent(container.pbox->getContent());
        }
        return *this;
    }

    Container& operator=(Container&& container) noexcept {
        this->pbox = std::move((container.pbox));
        if(verbose) cout << "Move assigment of Container\n";
        return *this;
    }

    ~Container(){
        if(verbose) cout << "Destroying Container \n";
        //delete pbox;
    }

    friend Container operator+(const Container & p1, const Container & p2);
    friend std::ostream & operator << (std::ostream & out, const Container & p){
        return (out << " [" << p.pbox->getContent() << "] ");
    }
};

bool Container::verbose = false;

inline Container operator+(const Container & p1, const Container & p2){
    Container suma(p1.pbox->getContent() + p2.pbox->getContent());
    return suma;
}
