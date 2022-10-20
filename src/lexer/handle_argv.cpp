#include "./handle_argv.hpp"

#include <vector>
#include <string>

#include "./handle_one_argv.hpp"

void handle_argv(std::vector<std::string> &argv) {
  for(auto i = argv.begin(); i != argv.end(); ++i) {
    handle_one_argv(*i);
  }
}
