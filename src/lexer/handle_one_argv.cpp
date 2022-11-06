#include "./handle_one_argv.hpp"

#include <iostream>
#include <vector>
#include <string>

#include "./GetOptionName.hpp"
#include "./GetOptionValue.hpp"
#include "./handle_option.hpp"
#include "./handle_filename.hpp"

#include "../parser/Operator.hpp"

void handle_one_argv(std::string &argv, std::vector<BasedOperator*> &operatorList) {
  if(argv[0] == '-') {
    handle_option(
      *new std::string(GetOptionName(argv).substr(1)),
      *new std::string(GetOptionValue(argv))
    );
    return;
  }
  handle_filename(argv, operatorList);
};
