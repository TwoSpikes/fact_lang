#include "./HandleFile.hpp"

#include <iostream>
#include <vector>
#include <string>

#include "../globals/rust_types.h"

#include "./MarkStatements.hpp"
#include "./ToOperators.hpp"
#include "./Operator.hpp"

void HandleFile(std::string &file, std::vector<BasedOperator*> &operatorList){
  std::cout << "HandleFile!\n";
  auto &marked = MarkStatements(file);
  for( auto it = marked.begin();
       it != marked.end();
       ++it                     ) {
    std::cout << *it << " ";
  }
  std::cout << "\n------\n" << file << "\n------" << std::endl;
  {
    auto f = file.begin();
    auto m = marked.begin();
    usize fi = 0;
    usize mi = 0;
    for( ;
	 f != file.end() &&
	   m != marked.end();
	 ++f, ++fi ) {
      std::cout << "it! f" << *f << " m" << *m << " fi" << fi << " mi" << mi << '\n';
      if( fi == *m ) {
	std::cout << "Eq!\n";
	try {
	  std::cout << ToOperators(file.substr(marked.size() > 1 ? marked[mi-1] : 0, *m), operatorList).GetName();
	  std::cout << ": succes\n";
	  ++m;
	  ++mi;
	} catch (std::string &e) {
	  std::cout << "Catch: " << e << std::endl;
	}
      }
    }
  }
  std::cout << "\n------" << std::endl;
}
