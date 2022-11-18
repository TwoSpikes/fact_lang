#include "./ParseToken.hpp"

#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <string>

#include "../globals/shift_t.hpp"
#include "../globals/rust_types.h"

#include "./ParsingException.hpp"
#include "./ParseAs<u8>.hpp"
#include "./Operator.hpp"

void ParseToken(std::string &src, std::vector<BasedOperator*> &operatorList) {
  std::cout << "ParseToken(src=\"" << src << "\")!\n";
  //parse as u8
  try {
    throw ParseAs<u8>(src);
  } catch (std::pair<u8, size_t> &e) {
    throw *new shift_t(e.second);
  } catch (int e) {
    if(e == -1) {
      throw *new ParsingException;
    }
    std::cout << "ParseToken: int: Unreachable\n";
  } catch (...) { std::cout << "ParseToken: Unreachable\n"; throw; }
}
