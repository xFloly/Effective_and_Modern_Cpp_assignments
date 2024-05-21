
#include "Solutions/FileSystem.h"

int main(){

  printDirectory(R"(C:\Users\soszy\Documents\studia\6\Cpp\Effective_and_Modern_Cpp\Ex11_Concepts_Filesystem_Regex)");
  printDirectory("/non_existing_path");


  fs::path directoryPath = R"(C:\Users\soszy\Documents\studia\6\Cpp\Effective_and_Modern_Cpp\Ex11_Concepts_Filesystem_Regex\Solutions)";
  std::string fileNamesRegex = ".*\\.txt";
  std::string newExtension = ".changed";
  changeExtension(directoryPath, fileNamesRegex, newExtension);

  return 0;
}
