#include "./handle_option.hpp"

#include <iostream>
#include <string>

#include "../conf/main.hpp"

#include "./cut_until_equal.hpp"

void handle_option(std::string &option) {
  if(cut_until_equal(option).compare("d") == 0) {
    std::cout << 'd';
  }
}
