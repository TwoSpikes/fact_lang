#include "./ToOperators.hpp"

#include <boost/format.hpp>

#include <iostream>
#include <vector>
#include <string>

#include "../globals/rust_types.h"

#include "./Operator.hpp"

BasedOperator &ToOperators(std::string src, std::vector<BasedOperator*> &operatorList) {
  for(auto it = operatorList.begin();
      it != operatorList.end();
      ++it) {
    if(!((*it)->GetName().compare(src))) {
      return **it;
    }
  }
  throw *new std::string(boost::str(boost::format("Operator not found: %1%") % src));
}
