#include <cstdio>
#include <string>

#include "../src/globals/rust_types.hpp"

int main(int argc, char** argv) {
  {
    for(u32 i = 0; i < argc; ++i) {
      std::string tmp{};
      for(u32 j = 0; argv[i][j] != '\0'; ++j) {
        tmp += argv[i][j];
      }
      printf("%s", tmp.c_str());
    }
  }
  return 0;
}
