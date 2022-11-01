#include "./handle_filename.hpp"

#include <iostream>

#include <fstream>
#include <string>

#include "../parser/HandleFile.hpp"

void handle_filename(std::string &filename) {
  std::ifstream istrm(filename, std::ios::binary);
  char *tmp = new char;
  istrm.read(tmp, 500);
  HandleFile(*new std::string(tmp));
}
