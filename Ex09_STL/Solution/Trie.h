
#ifndef LAB9_STL_TRIE_H
#define LAB9_STL_TRIE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;
/**
 * Trie structure
 *
 * HINT: use std::map to implement it!
 *       My implementation adds less than 25 lines of code.
 */
class Trie{
  map<string,Trie> data;

  static void recursivePrint(Trie *, const std::string&);
public:
  static void printSentence(const std::vector<std::string>  & );

  void add(const std::vector<std::string>  & );

  void printPossibleEndings(const std::vector<std::string>  & );

  void load(const std::string & );
};

#endif //LAB9_STL_TRIE_H
