#include "Templates.h"

#include <cstring>

template<typename T>
int compare(T a, T b){
    if (a < b){
        return 1;
    }
    if (b < a){
        return -1;
    }
    return 0;
}



template<typename T>
int compare(T* a, T* b){
    if (*a < *b){
        return 1;
    }
    if (*b < *a){
        return -1;
    }
    return 0;
}

template<>
int compare(const char * a, const char * b){
    return std::strcoll(a,b);
}


