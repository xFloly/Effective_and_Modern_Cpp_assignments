#include <iostream>
#include <vector>

#include "Solutions/Mixins.h"

using namespace std;


int main(){

    using RedCircle = Mixins<Red, Circle>;
    RedCircle x(Red{}, Circle{3});
    cout << x.color << " area = " << x.area() << endl;

    using BlueRectangleWithNotes = Mixins<Blue, Rectangle, Note>;
    BlueRectangleWithNotes y (Blue{}, Rectangle{3,4}, Note{"Hey"});
    y.add("Ho");
    cout << y.color << " area = " << y.area() << endl;

}