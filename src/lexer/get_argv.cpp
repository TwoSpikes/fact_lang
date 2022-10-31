#include "./get_argv.hpp"

#include <vector>
#include <string>

#include "../globals/rust_types.hpp"

#include "../lexer/get_one_argv.hpp"

std::vector<std::string> &get_argv(int argc, char** argv) {
  auto &res = *new std::vector<std::string>;
  for(u32 i = 1; i < argc; ++i) {
    res.push_back(get_one_argv(argv[i]));
  }
  return res;
}
