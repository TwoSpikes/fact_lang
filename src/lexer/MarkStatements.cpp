#include "./MarkStatements.hpp"

#include <string>
#include <vector>

std::vector<size_t> MarkStatements(std::string file) {
  auto &res = *new std::vector<size_t>;
  {
    size_t i = 0;
    for(auto it = file.begin(); it != file.end(); ++it, ++i) {
      if(*it == ';') {
	res.push_back(i);
      }
    }
  }
  return res;
}
