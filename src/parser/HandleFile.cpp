#include "./HandleFile.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "../globals/rust_types.h"
#include "../globals/StringLiteral.hpp"

#include "./TryParse.hpp"
#include "./Operator.hpp"

void HandleFile(std::string &file, std::vector<BasedOperator*> &operatorList) {
  std::cout << file << "\n------" << std::endl;
  {
    auto it = file.begin();
    usize i = 0;
    for( ;
	 it != file.end() &&
	   *it != ';';
	 ++it, ++i );
    std::cout << "Yeah: " << i << std::endl;
    {
      file.insert(0, 1, ' ');
      //previous i
      usize ip = 0;
      for( ;
	   it != file.end();
	   ++it, ++i ) {
	if( *it == ';' ) {
	  TryParse(file.substr(ip+1, i-ip-1), operatorList, true);
	  ip = i;
	}
      }
    }
  }
}
