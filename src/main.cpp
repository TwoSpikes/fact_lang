#include "./lexer/get_argv.hpp"
#include "./lexer/handle_argv.hpp"

#include <iostream>

int main(int argc, char** argv) {
  handle_argv(get_argv(argc, argv));
  return 0;
}
