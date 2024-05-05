
#ifndef LAB9_STL_WORDCOUNT_H
#define LAB9_STL_WORDCOUNT_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#pragma once
using namespace std;
void toLowerAlpha(std::string & s1);
void countWords(string);
void countWordFromUnordered(string);
void measureTime(void (*f)(string),string);
#endif //LAB9_STL_WORDCOUNT_H
