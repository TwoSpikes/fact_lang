#pragma once

#include <stdlib.h>
#include <utility>
#include <vector>
#include <string>

#include "./Operator.hpp"
#include "./ParseAs.hpp"

#define INTERNALERR 0
#define OPERNOTFOUND 1
#define NOSRC 2

std::pair<BasedOperator *, usize> *ParseAs(std::string src, std::vector<BasedOperator*> &operatorList);
