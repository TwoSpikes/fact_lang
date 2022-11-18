#include "./shift_t.hpp"

#include <stdlib.h>

shift_t::shift_t(size_t val): val(val) { }

shift_t shift_t::operator+=(size_t val) {
  return this->val += val;
}

shift_t::operator size_t() {
  return this->val;
}
