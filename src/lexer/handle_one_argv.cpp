#include "./handle_one_argv.hpp"

#include <string>

#include "./handle_option.hpp"

void handle_one_argv(std::string &argv) {
  if(argv[0] == '-') {
    handle_option(*new std::string(argv.substr(1)));
  } else {
    
  }
};
