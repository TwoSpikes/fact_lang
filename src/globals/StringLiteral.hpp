#pragma once

#include <algorithm>

#include "./rust_types.h"

template<size_t N>
struct StringLiteral {
  char value[N];
  inline constexpr StringLiteral(const char (&str)[N]) {
    std::copy_n(str, N, value);
  }
};
