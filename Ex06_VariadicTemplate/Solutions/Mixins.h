
#ifndef EX06_VARIADICTEMPLATE_MIXINS_H
#define EX06_VARIADICTEMPLATE_MIXINS_H
#include <iostream>
#include <vector>

class Red{
public:     static constexpr char color[] = "red";
};

class Yellow{
public:     static constexpr char color[] = "yellow";
};

class Blue{
public:     static constexpr char color[] = "blue";
};

class Circle{
    double r=0;
public:
    Circle() = default;
    Circle(double r): r(r) {}
    double area(){ return 3.24*r*r; }
};
class Rectangle{
    double a=0, b=0;
public:
    Rectangle() = default;
    Rectangle(double a, double b) : a(a), b(b) {}
    double area(){ return a * b;}
};

class Note{
    std::vector<std::string> notes;
public:
    Note(const std::string & note){
        add(note);
    }
    void add(const std::string & note){
        notes.push_back(note);
    }
};

template<class... Ts>
class Mixins : public Ts... {
public:
    Mixins(const Ts&... mixins) : Ts(mixins)... { }
};

#endif //EX06_VARIADICTEMPLATE_MIXINS_H
