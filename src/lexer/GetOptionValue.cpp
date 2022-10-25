#include "./GetOptionValue.hpp"

#include <string>

#include "./cut_from_equal.hpp"

std::string GetOptionValue(std::string &option) {
  try {
    return cut_from_equal(option);
  } catch(...) {
    return *new std::string;
  }
}
