#include "./parse_argv.hpp"

#include <vector>
#include <string>

#include "../globals/rust_types.hpp"

#include "../lexer/parse_one_argv.hpp"

std::vector<std::string> parse_argv(int argc, char** argv) {
  std::vector<std::string> res{};
  for(u32 i = 1; i < argc; ++i) {
    res.push_back(parse_one_argv(argv[i]));
  }
  return res;
}
