#pragma once

#include <string>

#include "../globals/rust_types.h"

#include "./ParseAs.hpp"
#include "./Operator.hpp"

template <>
u8 &ParseAs<u8>(std::string &src);
