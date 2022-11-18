#pragma once

#include <stdlib.h>
#include <vector>
#include <string>

#include "./Operator.hpp"
#include "./ParseAs.hpp"

std::pair<BasedOperator *, size_t> ParseAs(std::string src, std::vector<BasedOperator*> &operatorList);
