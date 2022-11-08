#pragma once

#include <vector>
#include <string>

#include "./Operator.hpp"
#include "./ParseAs.hpp"

BasedOperator &ParseAs(std::string src, std::vector<BasedOperator*> &operatorList);
