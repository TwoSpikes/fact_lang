#include <iostream>
#include <vector>
#include <string>

#include "../globals/rust_types.h"

#include "./Parse.hpp"
#include "./Operator.hpp"

void TryParse(std::string src, std::vector<BasedOperator *> &operatorList) {
  try {
    Parse(src, operatorList);
  } catch (std::string &e) {
    std::cout << e;
  } catch (u8 src) {
    std::cout << "Got u8: " << (int)src << std::endl;
  } catch (BasedOperator *src) {
    std::cout << "Operator: " << src->GetName() << std::endl;
  } catch (nullptr_t) { } catch (...){throw *new std::string("Unreachable");}
}
