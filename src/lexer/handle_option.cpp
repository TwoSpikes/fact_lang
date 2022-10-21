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
    DEBUG_MODE = str_to_bool(optionValue);
    std::cout << "Debug mode = " << DEBUG_MODE << std::endl;
  }
}
