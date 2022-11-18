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

std::pair<BasedOperator *, usize> ParseAs(std::string src, std::vector<BasedOperator*> &operatorList) {
  std::cout << "Parseasop: \"" << src << "\"\n";
  
  bool beenValidSymbol = false;
  // uninitialised
  bool isValid;
  {
    usize i = 0;
    for(auto it = src.begin(); it != src.end(); ++it, ++i) {
      isValid = IsValid(*it);
      if(isValid) {
	beenValidSymbol = true;
      }
      if(!isValid && (beenValidSymbol || *it == src[src.length()-1])) {
	for(auto it: operatorList) {
	  if(it->GetName().compare(src))
	    return {it, i};
	}
	throw *new std::string(boost::str(boost::format("Operator not found: \"%1%\"\n") % src));
      }
    }
  }
}
