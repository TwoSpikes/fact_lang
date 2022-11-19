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
  auto &opStack = *new std::vector<BasedOperation*>;
  std::cout << "[~] Parse src=\"" << src << "\"\n";
  shift_t tmp(0);
  for(; tmp < src.length();) {
    try {
      ParseToken(*new std::string(src.substr(tmp)), operatorList);
    } catch (shift_t &e) {
      tmp += e;
    } catch (std::pair<ConstOperation<u8>, shift_t &> &e) {
      std::cout << "  Parse: u8: " << e.first.GetVal() << std::endl;
      tmp += e.second;
    } catch (std::pair<BasedOperator *, shift_t> &e) {
      std::cout << "  Parse: Operator: " << e.first << std::endl;
      tmp += e.second;
    } catch (ParsingException &e) {
      std::cout << "  Parse: catch: ParsingException\n";
      return opStack;
    } catch (...) { std::cout << "[#] Parse: ParseToken: Unreachable\n"; throw; }
  }
}


