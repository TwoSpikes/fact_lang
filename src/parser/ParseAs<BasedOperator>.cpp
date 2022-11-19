#include "./ParseAs<BasedOperator>.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <stdlib.h>
#include <algorithm>

#include <boost/format.hpp>

#include "../globals/Exception.hpp"
#include "../globals/shift_t.hpp"

#include "./Operator.hpp"

//symbol is '+', '-', and others
bool IsValid(char src) {
  return !(src == ' ' ||
	   src == '_' ||
	   (src >= '0' &&
	    src <= '9') ||
	   isalpha(src));
}

std::pair<BasedOperator *, size_t> *ParseAs(std::string src, std::vector<BasedOperator*> &operatorList) {
  if(!IsValid(src[0])) { throw 1; }

  bool beenValidSymbol = false;
  bool isValid;
  {
    size_t i = 0;
    std::string tmp { };
    for(auto it = src.begin(); it != src.end(); ++it, ++i) {
      isValid = IsValid(*it);
      if(isValid) {
	beenValidSymbol = true;
      }
      // // in brackets last symbol is presented
      // if wrong symbol (like "+*+_")
      // and not empty ("_")
      if(!isValid && (beenValidSymbol)) {
	for( auto opit = operatorList.begin();
	     opit != operatorList.end();
	     ++opit ) {
	  if((*opit)->GetName().compare(src)) {
	    return new std::pair(*opit, i);
          }
	}
	//not found
	throw new Exception;
      }
    }
  }
}
