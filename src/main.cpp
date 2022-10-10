#include <cstdio>
#include <string>
#include <vector>

#include "./globals/rust_types.hpp"
#include "./parser/parse_argv.hpp"

int main(int argc, char** argv) {
  std::vector<std::string> tmp = parse_argv(argc, argv);
  for(std::string i : tmp) {
    printf("%s", i.c_str());
  }
  return 0;
}
