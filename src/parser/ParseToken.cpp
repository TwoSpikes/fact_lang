#include "./ParseToken.hpp"

#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <string>

#include "../globals/Exception.hpp"
#include "../globals/shift_t.hpp"
#include "../globals/rust_types.h"

#include "./ParsingException.hpp"
#include "./ParseAs<u8>.hpp"
#include "./ParseAs<BasedOperator>.hpp"
#include "./Operator.hpp"
#include "./Operation.hpp"

void ParseToken(std::string &src, std::vector<BasedOperator*> &operatorList) {
  std::cout << "  [~] ParseToken(src=\"" << src << "\")\n";

  //parse as u8
  std::cout << "    [~] parseasu8\n";
  try {
    auto tmp = ParseAs<u8>(src);
    throw *new std::pair(
		    tmp->first,
		    shift_t(tmp->second)
		    );
  } catch (Exception *) {
    std::cout << "      [#] ParseToken: none\n";
    throw *new shift_t(1);
  } catch (...) { std::cout << "      [#] ParseToken: Unreachable\n"; }

  //parse as operator
  std::cout << "    [~] parseasop\n";
  try {
    ParseAs(src + ' ', operatorList);
  } catch (Exception *) {
    throw *new shift_t(1);
  } catch (size_t e) { throw *new shift_t(1);
  } catch (...) { std::cout << "      [#] ParseToken: Unreachable\n"; }
}
