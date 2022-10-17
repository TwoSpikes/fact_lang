#include "./handle_option.hpp"

#include <iostream>
#include <string>

void handle_option(std::string &option) {
  if(option.compare("i") == 0) {
    std::cout << 'i';
  }
}
