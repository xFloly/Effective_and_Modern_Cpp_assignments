
#include "WordCount.h"
#include <map>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <utility>

void toLowerAlpha(std::string & s1) {
  s1.erase(std::remove_if(s1.begin(), s1.end(),
                          []( auto const& c ) -> bool { return !std::isalnum(c) && std::isalpha(c); } ), s1.end());
  std::transform(s1.cbegin(), s1.cend(),s1.begin(),[](auto c)->char {return std::tolower(c);});
}

void countWords(string fileName){
  int count = 0;
  std::string word;
  map<string, int> c;
  std::vector<int> v;

  std::filesystem::path filePath = std::filesystem::current_path() / ".." / fileName;
  std::ifstream in(filePath);
  if(!in){
    cerr << "Error when openning file " << fileName << endl;
    return;
  }
  while(in >> word) {
    toLowerAlpha(word);
    if(!word.empty()){
      if (c[word] == 0) {
        count++;
      }
      c[word]++;
    }
  }

  multimap<int, string> m2;
  for (const auto& p : c) {
    m2.insert({p.second, p.first});
  }


  cout << "Number of distinct words : " << count << endl;
  cout << "\nThe top 20 most popular words: \n";

  auto it = rbegin(m2);
  for (int i = 0; i < 20 && it != m2.rend(); ++i, ++it) {
    std::cout << it->second << " : " << it->first << std::endl;
  }
}


void countWordFromUnordered(string fileName){
  int count = 0;
  std::string word;
  unordered_map<string, int> c;
  std::vector<int> v;

  std::filesystem::path filePath = std::filesystem::current_path() / ".." / fileName;
  std::ifstream in(filePath);
  if(!in){
    cerr << "Error when openning file " << fileName << endl;
    return;
  }
  while(in >> word) {
    toLowerAlpha(word);
    if(!word.empty()){
      if (c[word] == 0) {
        count++;
      }
      c[word]++;
    }
  }

  multimap<int, string> m2;
  for (const auto& p : c) {
    m2.insert({p.second, p.first});
  }


  cout << "Number of distinct words : " << count << endl;
  cout << "\nThe top 20 most popular words: \n";

  auto it = rbegin(m2);
  for (int i = 0; i < 20 && it != m2.rend(); ++i, ++it) {
    std::cout << it->second << " : " << it->first << std::endl;
  }
}

void measureTime(void (*f)(string),string s) {
  auto start = std::chrono::steady_clock::now();

  f(std::move(s));

  auto end = std::chrono::steady_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

  std::cout << "Time taken: " << duration << " milliseconds" << std::endl;
}