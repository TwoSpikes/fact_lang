#include "./HandleFile.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "../globals/rust_types.h"
#include "../globals/StringLiteral.hpp"

#include "./Parse.hpp"
#include "./Operator.hpp"

void HandleFile(std::string &file, std::vector<BasedOperator*> &operatorList) {
  std::cout << file << "\n------" << std::endl;
  {
    auto f = file.begin();
    usize i = 0;
    usize m = 0;
    for( ;
	 f != file.end();
	 ++f, ++i ) {
      if( *f == ';' ) {
	try {
	  Parse(file.substr(m, i-m), operatorList, true);
	} catch (std::string &e) {
	  std::cout << e;
	} catch (u8 src) {
	  std::cout << (int)src;
	} catch (BasedOperator *src) {
	  std::cout << "Operator: " << src->GetName() << std::endl;
	} catch (nullptr_t) { }
      }
    }
  }
}
