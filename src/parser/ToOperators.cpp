#include "./ToOperators.hpp"

#include <string>

#include "../globals/rust_types.h"

#include "./Operator.hpp"

Operator &ToOperators(std::string &src) {
  return *new SpecificOperator<u8, u8, u8>("+");
}
