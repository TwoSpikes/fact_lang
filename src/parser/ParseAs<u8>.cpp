#include "./ParseAs<u8>.hpp"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <utility>

#include <boost/format.hpp>

#include "./ParseAs.hpp"
#include "./Operator.hpp"

template <>
std::pair<u8, size_t> &ParseAs<u8>(std::string &src) {
  auto &res = *new u8(0);
  size_t i = 0;
  for(auto it = src.begin(); it != src.end(); ++it, ++i) {
    if(*it >= '0' && *it <= '9') {
      res = res*10 + (*it - '0');
      continue;
    }
    if(!i) throw -1;
    throw *new std::pair<u8, size_t>(res, i);
  }
  return *new std::pair(res, i);
}
