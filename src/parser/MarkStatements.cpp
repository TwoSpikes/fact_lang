#include "./MarkStatements.hpp"

#include <string>
#include <vector>

#include "../globals/rust_types.h"

std::vector<usize> &MarkStatements(std::string file) {
  auto &res = *new std::vector<size_t>;
  {
    usize i = 0;
    usize j = 0;
    for(auto it = file.begin(); it != file.end(); ++it, ++i) {
      if(*it == ';') {
	res.push_back(j += i);
      }
    }
  }
  return res;
}
