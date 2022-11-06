#include <vector>
#include <string>

#include "./globals/rust_types.h"

#include "./parser/Operator.hpp"
#include "./lexer/get_argv.hpp"
#include "./lexer/handle_argv.hpp"

int main(int argc, char** argv) {
  auto &operatorList = *new std::vector<BasedOperator*>;
  operatorList.push_back(new Operator<u8, u8, u8>("+", [](u8 a, u8 b) -> u8 {
    return a + b;
  }));
  handle_argv(*new std::vector<std::string>(get_argv(argc, argv)), operatorList);
  return 0;
}
