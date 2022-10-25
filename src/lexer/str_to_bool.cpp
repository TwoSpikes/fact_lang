#include "./str_to_bool.hpp"

#include <boost/format.hpp>
#include <iostream>
#include <string>

bool can_str_to_bool(std::string &src) {
  try {
    str_to_bool(src);
    return true;
  } catch(...) {
    return false;
  }
}

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
  throw boost::str(boost::format("Unknown value for `string` to `bool` conversion: `%1%` (must be `true`, `yes`, `1`, `false`, `no` or `0`)\n") % src);
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
