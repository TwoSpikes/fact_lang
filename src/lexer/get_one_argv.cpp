#include "./get_one_argv.hpp"

#include <string>

#include "../globals/rust_types.h"

std::string &get_one_argv(char* argv) {
  auto &res = *new std::string();
  for(u32 i = 0; argv[i] != '\0'; ++i) {
    res += argv[i];
  }
  return res;
}
