#include "./handle_argv.hpp"

#include <iostream>
#include <vector>
#include <string>

void handle_argv(std::vector<std::string> argv) {
  for(auto i = argv.begin(); i != argv.end(); ++i) {
    std::cout << *i << std::endl;
  }
}
