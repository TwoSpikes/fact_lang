#include <iostream>
#include <vector>
#include <string>

#include "../globals/rust_types.h"

#include "./Parse.hpp"
#include "./Operator.hpp"
#include "./Operation.hpp"

void TryParse(std::string src, std::vector<BasedOperator *> &operatorList) {
  std::vector<BasedOperation*> tmp;
  try {
    tmp = Parse(src, operatorList);
  } catch (std::string &e) {
    std::cout << e;
  } catch (u8 src) {
    std::cout << "Got u8: " << (int)src << std::endl;
  } catch (BasedOperator *src) {
    std::cout << "Operator: \"" << src->GetName() << "\"\n";
  } catch (std::pair<BasedOperator*, usize> &e) {
    std::cout << "Operator: \"" << e.first->GetName() << "\"\n";
  } catch (...) { std::cout << "TryParse: unreachable\n"; }
  for(auto it = tmp.begin(); it != tmp.end(); ++it) {
    std::cout << "Operation: " << (*it)->GetName() << std::endl;
  }
}
