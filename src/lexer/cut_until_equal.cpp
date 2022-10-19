#include "./cut_until_equal.hpp"

#include <iostream>
#include <string>

#include "../globals/rust_types.hpp"

std::string cut_until_equal(std::string &string) {
  u32  i  { };
  auto it { string.begin() };
  
  for(; it != string.end(); ++it, ++i)
    if(*it == '=')
      return string.substr(0,(u64)i);
  
  return string;
}
