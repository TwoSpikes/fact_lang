#pragma once

#include <vector>
#include <string>

#include "../parser/Operator.hpp"

void handle_argv(std::vector<std::string> &argv, std::vector<BasedOperator*> &operatorList);
