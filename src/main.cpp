#include <cstdio>
#include <string>
#include <vector>

#include "./globals/rust_types.hpp"
#include "./parser/parse_argv.hpp"

int main(int argc, char** argv) {
  std::vector<std::string> tmp = parse_argv(argc, argv);
  for(u32 i{}; i < tmp.size(); ++i) {
    printf("%s", tmp[i].c_str());
  }
  return 0;
}
