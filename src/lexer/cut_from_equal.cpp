#include "./cut_from_equal.hpp"

#include <iostream>
#include <string>

#include "../globals/rust_types.h"

std::string &cut_from_equal(std::string &src) {
  {
    u32  i  { };
    auto it { src.begin() };
    for(; it != src.end(); ++it, ++i) {
      if(*it == '=') {
	auto &res {
	  *new std::string(src.substr((u64)i+1))
	};
	return res;
      }
    }
    throw -1;
  }
}
