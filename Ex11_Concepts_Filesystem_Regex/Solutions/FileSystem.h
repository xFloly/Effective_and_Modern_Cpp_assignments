#ifndef EX11_CONCEPTS_FILESYSTEM_REGEX_FILESYSTEM_H
#define EX11_CONCEPTS_FILESYSTEM_REGEX_FILESYSTEM_H

#include <filesystem>
#include <iostream>
#include <regex>

namespace fs = std::filesystem;
/**
 * Prints content of directory given by path
 * Format
 * [X] file_name file_size
 * where X equals D for directories, F for regular files, L for symlinks and space otherwise.
 * @param path directory path
 */
void printDirectory (std::string_view path){
  try {
    if (!fs::is_directory(path)) {
      std::cout << "Path is not a directory path." << std::endl;
      return;
    }
    for (const auto& entry : fs::directory_iterator(path)) {
      char fileType = '-';
      if (fs::is_directory(entry.status()))
        fileType = 'D';
      else if (fs::is_regular_file(entry.status()))
        fileType = 'F';
      else if (fs::is_symlink(entry.status()))
        fileType = 'L';

      auto filename = entry.path().filename().string();
      std::cout << "[" << fileType << "] " << filename;
      if (fileType == 'F') {
        std::cout << " " << entry.file_size();
      }
      std::cout <<  std::endl;
    }
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() <<  std::endl;
  }
}

/**
 * Makes copies of all files matching fileNames regular expression in directory given by path
 * to files in the same directory but with changes extension to newExtension
 * @param path directory path
 * @param fileNames regular expression
 * @param newExtension new extension
 */
void changeExtension(fs::path path, std::string fileNames, std::string_view newExtension ) {
  try {
    if (!fs::is_directory(path)) {
      std::cout << "Path is not a directory path." << std::endl;
      return;
    }
    std::regex regexPattern(fileNames);
    for (const auto &entry: fs::directory_iterator(path)) {
      if (fs::is_regular_file(entry)) {
        std::string filename = entry.path().filename().string();
        if (std::regex_match(filename, regexPattern)) {
          fs::path newFilePath = entry.path().parent_path() / entry.path().stem();
          newFilePath += newExtension;
          fs::copy_file(entry.path(), newFilePath, fs::copy_options::overwrite_existing);
        }
      }
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}


#endif //EX11_CONCEPTS_FILESYSTEM_REGEX_FILESYSTEM_H
