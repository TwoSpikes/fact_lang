#pragma once

#include <vector>
#include <string>

#include "./Operator.hpp"
#include "./ParseAs.hpp"

std::tuple<BasedOperator *, usize> ParseAs(std::string src, std::vector<BasedOperator*> &operatorList);
