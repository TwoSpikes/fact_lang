#pragma once

#include <vector>
#include <string>
#include <typeinfo>
#include <utility>

#include "./Operator.hpp"

void Parse(std::string src, std::vector<BasedOperator*> &operatorList, bool clearStack = false);
