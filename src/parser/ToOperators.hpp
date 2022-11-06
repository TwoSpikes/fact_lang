#pragma once

#include <vector>
#include <string>

#include "./Operator.hpp"

BasedOperator &ToOperators(std::string src, std::vector<BasedOperator*> &operatorList);
