#include "./cut_until_equal.hpp"

#include <iostream>
#include <string>

#include "../globals/rust_types.h"

std::string &cut_until_equal(std::string &string) {
  u32  i  { };
  auto it { string.begin() };
  
  for(; it != string.end(); ++it, ++i)
    if(*it == '=')
      return *new std::string( string.substr(0,(u64)i) );
  
  throw -1;
}
