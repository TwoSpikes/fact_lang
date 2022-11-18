#pragma once

#include <vector>
#include <string>

#include "../globals/rust_types.h"

#include "./Operator.hpp"

void TryParse(std::string src, std::vector<BasedOperator *> &operatorList);
