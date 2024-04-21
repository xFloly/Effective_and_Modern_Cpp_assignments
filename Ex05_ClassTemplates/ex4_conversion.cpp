#include <iostream>
#include <iomanip>
using namespace std;
#include "dynamicVector.h"
#include "staticVector.h"

template <int N>
using SWektor = Vector<double, N>;
using DWektor = Vector<double, 0>;

int main(){
    cout <<fixed << setprecision(2);

	DWektor m1 = {1,  2,  3};    // dynamic z initialization_list
	cout << m1 << endl;

	SWektor<3> m2 = {1, -1, 0};  // static
    cout << m2 << endl;

    auto m3 = (SWektor<3>)(m1);  // conversion from dynamic to static
    cout << m3 << endl;

    auto m4 = m1 + m2 + m1;
    cout << m4 << endl;

    auto m5 = static_cast<DWektor>(m4);
    cout << m5 << endl;

    auto m6 = (SWektor<6>)(m2);
    cout << m6 << endl;

    DWektor m7 = {1.,2.,3.,4.};
    cout << (Vector<int,6>)m7 << endl;

    auto m8 = (Vector<int,0>) (m7);
    m7[1] = 7;
    cout << m8 << endl;

    auto m8o5 = (Vector<int>) (m7);
    cout << m8o5 << endl;

    auto m9 = (SWektor<9>)m8;
    m8[1] = 7;
    cout << m9 << endl;

    return 0;
}
