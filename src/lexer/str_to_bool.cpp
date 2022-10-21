#include "./str_to_bool.hpp"

#include <iostream>
#include <string>

bool str_to_bool(std::string &src) {
  if(
    !src.compare("true") ||
    !src.compare("yes") ||
    !src.compare("1")
  ) {
    return true;
  }
  if(
    !src.compare("false") ||
    !src.compare("no") ||
    !src.compare("0")
  ) {
    return false;
  }
  throw -1;
}

bool str_to_bool(std::string &src, bool alt) {
  if(
    !src.compare("true") ||
    !src.compare("yes") ||
    !src.compare("1")
  ) {
    return true;
  }
  if(
    !src.compare("false") ||
    !src.compare("no") ||
    !src.compare("0")
  ) {
    return false;
  }
  return alt;
}
