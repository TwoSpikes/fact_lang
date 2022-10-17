#include "./lexer/get_argv.hpp"
#include "./lexer/handle_argv.hpp"

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv) {
  handle_argv(*new std::vector<std::string>(get_argv(argc, argv)));
  return 0;
}
