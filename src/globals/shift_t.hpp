#pragma once

#include <stdlib.h>

struct shift_t {
  size_t val;
  shift_t(size_t val);
  shift_t operator+=(size_t val);
  operator size_t();
};
