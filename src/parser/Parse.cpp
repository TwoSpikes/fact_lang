#include "./Parse.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <typeinfo>

#include "../globals/rust_types.h"

#include "./Operator.hpp"
#include "./ParseAs<BasedOperator>.hpp"
#include "./ParseAs<u8>.hpp"

void Parse(std::string src, std::vector<BasedOperator*> &operatorList, bool clearStack) {
  static u8 stack = 0;
  if(clearStack) {
    stack = 0;
    std::cout << "New ";
  }
  if(!src.length()) { throw nullptr; }
  std::cout << "Parsing... src=\"" << src << "\" stack=" << (int)stack << '\n';

  //if space
  if(src[0] == ' ') {
    std::cout << "  Space!" << std::endl;
    try {
      Parse(src.substr(1), operatorList);
    } catch (...) {
      throw;
    }
  }
  
  // Parse as u8
  try {
    throw stack += ParseAs<u8>(src);
  } catch (std::tuple<std::string&, u8, usize> &e) {
    stack += std::get<1>(e);
    std::cout << "  stack=" << (int)stack << std::endl;
    try {
      Parse(src.substr( std::get<2>(e)+1 ), operatorList);
    } catch (...) {
      throw;
    }
  } catch (int e) {
    if(e == -1) {
      
    } else {
      throw *new std::string("Unreachable\n");
    }
  }
  
  // Parse as Operator
  try {
    auto tmp = ParseAs(src, operatorList);
    throw std::get<0>(tmp);
    try {
      Parse(src.substr(std::get<1>(tmp)+1), operatorList);
    } catch (...) { throw; }
  } catch(std::string &e) {
    throw;
  }

  std::cout << "  Final stack: " << (int)stack << std::endl;
  throw nullptr;
}
