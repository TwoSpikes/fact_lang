#include "./lexer/get_argv.hpp"
#include "./lexer/handle_argv.hpp"
#include "./parser/Operator.hpp"
#include "./globals/rust_types.h"

#include <iostream>
//#include <vector>
//#include <string>

//int main(int argc, char** argv) {
//handle_argv(*new std::vector<std::string>(get_argv(argc, argv)));
//return 0;
//}

int main() {
  Operator<u8, u8, u8> a {
    "+",
    [](u8 a, u8 b) -> u8 {
      return a + b;
    }
  };
  std::cout << (int)a.algorithm(5,6) << std::endl;
}
