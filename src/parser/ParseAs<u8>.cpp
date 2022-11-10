#include "./ParseAs<u8>.hpp"

#include <iostream>
#include <string>
#include <utility>

#include <boost/format.hpp>

#include "../globals/rust_types.h"

#include "./ParseAs.hpp"
#include "./Operator.hpp"

template <>
u8 &ParseAs<u8>(std::string &src) {
  auto &res = *new u8(0);
  {
    usize i = 0;
    for(auto it = src.begin(); it != src.end(); ++it, ++i) {
      if(*it >= '0' && *it <= '9') {
        res = res*10 + (*it - '0');
        continue;
      }
      if(!i) {
	throw -1;
      }
      throw *new std::tuple<std::string&, u8, usize>(*new std::string(boost::str(boost::format("Cannot convert \"%1%\" to u8\n") % src)), res, i);
    }
  }
  return res;
}
