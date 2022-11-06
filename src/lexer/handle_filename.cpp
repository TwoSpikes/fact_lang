#include "./handle_filename.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../parser/HandleFile.hpp"
#include "../parser/Operator.hpp"

void handle_filename(std::string &filename, std::vector<BasedOperator*> &operatorList) {
  std::ifstream istrm(filename, std::ios::binary);
  char *tmp = new char;
  istrm.read(tmp, 500);
  HandleFile(*new std::string(tmp), operatorList);
}
