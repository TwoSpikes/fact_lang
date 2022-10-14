#include "./get_one_argv.hpp"

#include <string>

#include "../globals/rust_types.hpp"

std::string get_one_argv(char* argv) {
  std::string *res = new std::string();
  for(u32 i = 0; argv[i] != '\0'; ++i) {
    res[0] += argv[i];
  }
  return *res;
}
