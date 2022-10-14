#include <iostream>
#include <string>
#include <vector>

#include "./globals/rust_types.hpp"

#include "./lexer/get_argv.hpp"

int main(int argc, char** argv) {
  auto tmp = new std::vector<std::string>(get_argv(argc, argv));
  for(auto i = tmp->begin(); i != tmp->end(); i++) {
    std::cout << i->c_str();
  }
  return 0;
}
