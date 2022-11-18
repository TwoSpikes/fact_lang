#pragma once

#include <vector>
#include <string>

#include "./Operator.hpp"

void ParseToken(std::string &src, std::vector<BasedOperator*> &operatorList);
