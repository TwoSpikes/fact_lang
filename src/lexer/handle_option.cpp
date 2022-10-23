#include "./handle_option.hpp"

#include <exception>
#include <iostream>
#include <string>

#include "../conf/main.hpp"
extern bool DEBUG_MODE;

#include "./cut_until_equal.hpp"
#include "./cut_from_equal.hpp"
#include "./str_to_bool.hpp"

void handle_option(std::string &option) {
  auto &optionName { *new std::string( cut_until_equal(option) ) };
  if(optionName.compare("d") == 0) {
    auto &optionValue { *new std::string( cut_from_equal(option) ) };
    std::cout << "Debug mode = " << DEBUG_MODE << std::endl;
    try {
      DEBUG_MODE = str_to_bool(optionValue);
    } catch(...) {
      std::cout << "Unknown value for `-d` option: `" << optionValue << "` (must be `true`, `yes`, `1`, `false`, `no` or `0`)" << std::endl;
    }
    std::cout << "Debug mode = " << DEBUG_MODE << std::endl;
  }
}
