#include "./handle_option.hpp"

#include <iostream>
#include <string>

#include "./str_to_bool.hpp"

void handle_option_d(std::string &optionValue, bool DEBUG_MODE) {
  std::cout << "Debug mode = " << DEBUG_MODE << std::endl;
  try {
    DEBUG_MODE = str_to_bool(optionValue);
  } catch(std::string &e) {
    std::cout << e;
  }
  std::cout << "Debug mode = " << DEBUG_MODE << std::endl;
}
