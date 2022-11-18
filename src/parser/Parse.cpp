#include "./Parse.hpp"

#include <iostream>
#include <vector>
#include <string>

#include "../globals/shift_t.hpp"
#include "../globals/rust_types.h"

#include "./ParsingException.hpp"
#include "./Operation.hpp"
#include "./Operator.hpp"
#include "./ParseToken.hpp"

std::vector<BasedOperation*> &Parse(std::string src, std::vector<BasedOperator*> &operatorList) {
  //parse as u8
  auto &opStack = *new std::vector<BasedOperation*>;
  std::cout << "Parse(src=\"" << src << "\")!\n";
  shift_t tmp(0);
  for(; tmp < src.length();) {
    try {
      ParseToken(*new std::string(src.substr(tmp)), operatorList);
    } catch (u8 e) {
      opStack.push_back(new ConstOperation<u8>(e));
    } catch (shift_t &e) {
      tmp += e;
    } catch (ParsingException &e) {
      std::cout << "Parse: catch: ParsingException\n";
      break;
    } catch (...) { throw; }
  }

  //parse as operator

  return opStack;
}


