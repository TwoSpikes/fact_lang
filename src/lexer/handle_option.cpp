#include "./handle_option.hpp"

#include <iostream>
#include <string>

#include "../conf/main.hpp"

#include "./cut_until_equal.hpp"
#include "./cut_from_equal.hpp"

void handle_option(std::string &option) {
  auto optionName { new std::string( cut_until_equal(option) ) };
  if(optionName.compare("d") == 0) {
    auto optionValue { new std::string( cut_from_equal(option) ) };
    std::cout << optionValue;
  }
}
