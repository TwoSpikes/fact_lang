#include "./handle_option.hpp"

#include <iostream>
#include <string>

#include "./handle_option_d.hpp"

void handle_option(std::string &optionName, std::string &optionValue) {
  if(!optionName.compare("d")) {
    handle_option_d(optionValue);
    return;
  }
  std::cout << "Unknown option: " << optionName << std::endl;
}
