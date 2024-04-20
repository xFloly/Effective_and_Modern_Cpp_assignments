#include <iostream>
#include <limits>
#include <iostream>
#include <iomanip>
#include <type_traits>
using  namespace std;
/**
 * Outputs information about numerical type T:
 * (un)signed, (not) integer, min & max values
*/

template <typename T>
void info(T x, int w = 12){
    std::string sign;
    if constexpr (std::is_signed<T>::value) {
        sign = "signed";
    } else {
        sign = "unsigned";
    }

    std::string is_int;
    if constexpr (std::is_integral<T>::value){
        is_int = "integer";
    } else {
        is_int = "not integer";
    }

    auto min = std::numeric_limits<T>::min();
    auto max = std::numeric_limits<T>::max();

    cout << setw(w) << sign << ", "
         << setw(w) << is_int << ", "
         << setw(w) << "min"<< " : " << min
         << setw(w) << "max" << " : " << max
         << endl;
}

int main() {
    info(1);
    info(2.0f);
    info(3U);
    return 0;
}
/**
 * Expected output:
    signed,  integer, min : -2147483648 max : 2147483647
    signed, not integer, min : 1.17549e-38 max : 3.40282e+38
    unsigned,  integer, min : 0 max : 4294967295
 */