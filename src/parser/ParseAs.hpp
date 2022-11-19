#pragma once

#include <stdlib.h>
#include <string>
#include <utility>

#include "./Operation.hpp"

template <typename T>
std::pair<ConstOperation<T>, size_t> *ParseAs(std::string &src);
