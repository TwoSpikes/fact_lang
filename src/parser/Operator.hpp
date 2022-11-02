#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <string>

#include "../globals/rust_types.h"

template <typename ReturnType, typename... Types>
struct Operator {
public:
  const std::string name;
  ReturnType (*algorithm)(Types...);
};
