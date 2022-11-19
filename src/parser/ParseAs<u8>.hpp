#pragma once

#include <stdlib.h>
#include <string>
#include <utility>

#include "../globals/rust_types.h"

#include "./ParseAs.hpp"
#include "./Operation.hpp"

template <>
std::pair<ConstOperation<u8>, size_t> *ParseAs<u8>(std::string &src);
