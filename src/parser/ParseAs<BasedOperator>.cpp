#include "./ParseAs<BasedOperator>.hpp"

#include <boost/format.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

#include "../globals/rust_types.h"

#include "./Operator.hpp"

bool IsValid(char src) {
  return !(src == ' ' ||
	   (src >= '0' &&
	    src <= '9'));
}

std::tuple<BasedOperator *, usize> ParseAs(std::string src, std::vector<BasedOperator*> &operatorList) {
  bool beenValidSymbol = false;
  bool isValid;
  for(auto it = src.begin(); it != src.end(); ++it) {
    isValid = IsValid(*it);
    if(isValid) {
      beenValidSymbol = true;
    }
    if(!isValid && (beenValidSymbol || it == --src.end())) {
      {
	usize i = 0;
	for(auto it = operatorList.begin(); it != operatorList.end();
	    ++it, ++i) {
	  if(it[0]->GetName().compare(src)) {
	    return {*it, i};
	  }
	}
      }
      throw *new std::string(boost::str(boost::format("Operator not found: \"%1%\"\n") % src));
   }
  }
}
