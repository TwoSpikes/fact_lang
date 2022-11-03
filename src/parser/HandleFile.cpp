#include "./HandleFile.hpp"

#include <iostream>
#include <vector>
#include <string>

#include "./MarkStatements.hpp"
#include "./ToOperators.hpp"

void HandleFile(std::string &file) {
  auto marked = MarkStatements(file);
  auto &tmp = *new std::string(file);
  for( auto it = marked.begin();
       it != marked.end();
       ++it                     ) {
    std::cout << *it << ",";
  }
  std::cout << "\n------\n" << file << std::endl;
  for( auto it = marked.begin();
       it != marked.end();
       ++it                     ) {
    std::cout << ToOperators(tmp = tmp.substr(*it)).GetName();
  }
  std::cout << "\n------\n" << file << std::endl;
}
