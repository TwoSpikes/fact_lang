#include "./HandleFile.hpp"

#include <iostream>
#include <vector>
#include <string>

#include "./MarkStatements.hpp"

void HandleFile(std::string &file) {
  {
    auto marked = MarkStatements(file);
    std::cout << marked.size() << std::endl;
    std::cout << "{ ";
    for(
	auto it = marked.begin();
	it != marked.end();
	++it
	)
      std::cout << *it << ", ";
    std::cout << " }" << std::endl;
  }
  std::cout << file << std::endl;
}
