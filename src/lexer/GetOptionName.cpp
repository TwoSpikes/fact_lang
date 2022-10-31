#include "./GetOptionName.hpp"

#include <string>

#include "./cut_until_equal.hpp"

std::string &GetOptionName(std::string &option) {
  try {
    return cut_until_equal(option);
  } catch(...) {
    return *new std::string;
  }
}
