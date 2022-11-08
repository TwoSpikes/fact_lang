
#include <vector>
#include <string>

#include "./globals/rust_types.h"

#include "./parser/Operator.hpp"
#include "./lexer/get_argv.hpp"
#include "./lexer/handle_argv.hpp"

int main(int argc, char** argv) {
  auto &operatorList = *new std::vector<BasedOperator*>;
  {
    //constexpr std::string_view operatorName = "+";
    operatorList.push_back(new Operator<"+", u8, u8, u8>([](std::vector<void*> const &) -> u8* {
      return new u8;
    }));
  }
  handle_argv(*new std::vector<std::string>(get_argv(argc, argv)), operatorList);
  return 0;
}
