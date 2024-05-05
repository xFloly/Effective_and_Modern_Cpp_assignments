#include <iostream>
#include <vector>

#include "Solution/Anagram.h"

int main(){

    constexpr int N = 10;
    std::vector<int> v(N);

    //4. Fill vector v with consecutive numbers starting with -5. (Hint: use std::iota)
    // <<>> (1 line)
    std::iota(v.begin(),v.end(),-5);
    print(v);

    std::vector<int> odd;
    //5. Copy to odd all odd numbers from v (Hint: use copy_if and back_inserter)
    // <<>> (1 line)
    std::copy_if(v.begin(),v.end(),std::back_inserter(odd),[](int& x)->bool {return x%2!=0;});
    print(odd);

    //6. Each number x in v replace with x*x-1 (Hint std::transform)
    // <<>> (1 line)
    std::transform(v.cbegin(),v.cend(),v.begin(),[](int x)->int{return x*x-1;});
    print(v);

    std::vector<int> intersect;
    //7. Sort v and compute intersection of vectors odd and v (treated as sets)
    // <<>> (2 lines)
    std::sort(v.begin(),v.end());
    std::set_intersection(odd.begin(),odd.end(),v.begin(),v.end(),std::back_inserter(intersect));
    print(intersect);

    isAnagramTest("male", "lame", true);
    isAnagramTest(" Ala $%", "%%Ala%%ska%", false);
    isAnagramTest(" Ala $%", "%%la%%a%", true);
    isAnagramTest("A l a", "ALA", false);
}
/* Expected output
 *
-5, -4, -3, -2, -1, 0, 1, 2, 3, 4,
-5, -3, -1, 1, 3,
24, 15, 8, 3, 0, -1, 0, 3, 8, 15,
-1, 3,
isAnagram("male", "lame") = true [OK]
isAnagram(" Ala $%", "%%Ala%%ska%") = false [OK]
isAnagram(" Ala $%", "%%la%%a%") = true [OK]
isAnagram("A l a", "ALA") = false [OK]
 */
