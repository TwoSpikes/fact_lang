#pragma once

namespace TS {
  template <typename A, typename B>
  constexpr bool are_same(A a, B b) {
    return false;
  }

  template <typename A>
  constexpr bool are_same(A a, A b) {
    return true;
  }
}
