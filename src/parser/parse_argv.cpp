#include "./parse_argv.hpp"

#include <vector>
#include <string>

#include "../globals/rust_types.hpp"

std::vector<std::string> parse_argv(int argc, char** argv) {
  std::vector<std::string> res{};
  for(u32 i = 0; i < argc; ++i) {
    res.push_back(*new std::string());
    for(u32 j = 0; argv[i][j] != '\0'; ++j) {
      res[res.size() - 1] += argv[i][j];
    }
  }
  return res;
}
