#include "./ToOperators.hpp"

#include <string>

#include "../globals/rust_types.h"

#include "./Operator.hpp"

BasedOperator &ToOperators(std::string &src) {
  return *new Operator<u8, u8, u8>("+", [](u8 a, u8 b) -> u8 {
    return a + b;
  });
}
