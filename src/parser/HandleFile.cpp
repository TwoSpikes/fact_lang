#include "./HandleFile.hpp"

#include <iostream>
#include <vector>
#include <string>

#include "../globals/rust_types.h"
#include "../globals/StringLiteral.hpp"

#include "./ParseAs<BasedOperator>.hpp"
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
	  StringLiteral tmp = ParseAs(file.substr(m, i-m), operatorList).GetName;
	  std::cout << tmp.value <<
	    std::endl;
	} catch (std::string &e) {
	  std::cout << e << std::endl;
	}
	m = i+1;
      }
    }
  }
}
