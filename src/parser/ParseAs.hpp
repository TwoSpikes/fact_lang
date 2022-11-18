#pragma once

#include <stdlib.h>
#include <string>
#include <utility>

#include "./Operator.hpp"

template <typename T>
std::pair<T, size_t> &ParseAs(std::string &src);
