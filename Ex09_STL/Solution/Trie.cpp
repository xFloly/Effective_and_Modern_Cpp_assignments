#include "Trie.h"
void Trie::printSentence(const std::vector<std::string>  & sentence ){
  for(const auto & w : sentence)
    cout << w << " ";
}

void Trie::add(const std::vector<std::string>  & sentence ){
  cout << "Adding : ";
  printSentence(sentence);
  cout << "\n";

  auto node = this;
  for(auto&& iter : sentence){
    auto word = iter.data();
    if (node->data.contains(word)){
      node->data.emplace(word,Trie());
    }
    node = &node->data[word];
  }
}

void Trie::printPossibleEndings(const std::vector<std::string>  & beginningOfSentece ){
  cout << "Endings for \"";
  printSentence(beginningOfSentece);
  cout << "\" are :\n";

  auto node = this;
  for(auto&& iter : beginningOfSentece){
    auto word = iter.data();
    if (node->data.contains(word)){
      node = &node->data[word];
    } else {
      return;
    }
  }

  recursivePrint(node, std::string());
}

void Trie::recursivePrint(Trie* node, const std::string& sentence) {
  if (node->data.empty()) {
    std::cout << sentence << std::endl;
  } else {
    for (auto&& iter : node->data) {
      auto word = iter.first;
      auto next = &iter.second;
      std::string newSentence = sentence.empty() ? word : sentence + " " + word;
      recursivePrint(next, newSentence);
    }
  }
}


void Trie::load(const std::string & fileName){
  ifstream file(fileName);
  if(!file){
    cerr << "Error when openning file " << fileName << endl;
    return;
  }
  string word;
  vector<string> sentence;
  while( file >> word) {
    sentence.push_back(word);
    // is it end of the sentence?
    if(word.find_last_of('.') != string::npos) {
      add(sentence);
      sentence.clear();
    }
  }
}