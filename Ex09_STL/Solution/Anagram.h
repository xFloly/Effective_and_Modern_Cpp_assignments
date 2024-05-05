#ifndef LAB9_STL_ANAGRAM_H
#define LAB9_STL_ANAGRAM_H
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cctype>

template <typename Container>
void print(const Container & c){
  //1.  Print elements of the container separated by ", "
  //    using std::copy and std::ostream_iterator
  // <<>> (1 line)
  std::copy(c.begin() ,c.end() ,std::ostream_iterator<double>(std::cout, ", "));
  std::cout << std::endl;
}

/**
 * Removes all non alphanumeric characters from given word and converts to lower case.
 * @param[in,out] word on return word consist only of lower case characters.
 */
void toLowerAlpha(std::string & s1) {
  //2. Implement using stl algorithms only
  //   Hint: use remove_if, transform, erase
  s1.erase(std::remove_if(s1.begin(), s1.end(),
                         []( auto const& c ) -> bool { return !std::isalpha(c); } ), s1.end());
  std::cout<<s1<<std::endl;
  std::transform(s1.cbegin(), s1.cend(),s1.begin(),[](auto c)->char {return std::tolower(c);});
}
/**
  Checks if the first word is an anagram of the second word.

     - All non alphanumeric chars are ignored (remove them).
     - It is case insensitive (convert to lower case).
     - Words cannot be the same (at least one change needed).
     - They should contain the same letters (sort letters in each word to compare).

  @param word1 not empty string
  @param word2 not empty string
  @return true if and only if word1 is an anagram of word2.
*/
bool isAnagram(std::string word1, std::string word2){
//3. Implement isAnagram function using stl algorithms only
//   Hint: use toLowerAlpha, sort, equal
// <<>> (several lines)
  toLowerAlpha(word1);
  std::sort(word1.begin(), word1.end());

  toLowerAlpha(word2);
  std::sort(word2.begin(), word2.end());

  return std::equal(word1.begin(),word1.end(),word2.begin());
}
void isAnagramTest(const std::string & s1, const std::string & s2, bool expected){
  std::cout << "isAnagram(\"" << s1 << "\", \""<< s2 << "\") = ";
  bool result = isAnagram(s1, s2);
  std::cout << std::boolalpha << result
            << ((result == expected)? " [OK]": " [ERROR]") << std::endl;
}

#endif //LAB9_STL_ANAGRAM_H
