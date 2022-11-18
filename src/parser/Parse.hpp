#pragma once

#include <vector>
#include <string>
#include <typeinfo>
#include <utility>

#include "./Operation.hpp"
#include "./Operator.hpp"

std::vector<BasedOperation*> &Parse(std::string src, std::vector<BasedOperator*> &operatorList);
