#include "./ParseAs<u8>.hpp"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <utility>

#include <boost/format.hpp>

#include "../globals/Exception.hpp"
#include "../globals/shift_t.hpp"

#include "./ParseAs.hpp"
#include "./Operator.hpp"
#include "./Operation.hpp"

template <>
std::pair<ConstOperation<u8>, size_t> *ParseAs<u8>(std::string &src) {
  auto &res = *new u8(0);
  size_t i = 0;
  for(auto it = src.begin(); it != src.end(); ++it) {
    //valid
    if(*it >= '0' && *it <= '9') {
      res = res*10 + (*it - '0');
      i += 1;
      continue;
    }
    std::cout << "      i=" << i << " res=" << (int)res << std::endl;
    if(!i) {
      throw new Exception;
    }
    //not valid
    return new std::pair(*new ConstOperation<u8>(res), i);
  }
  //all valid
  return new std::pair(*new ConstOperation<u8>(res), src.length());
}
