#pragma once

#include <type_traits>
#include <vector>
#include <string>

#include "../globals/CountTypes.hpp"
#include "../globals/are_same.hpp"

class BasedOperation {
public:
  virtual std::string const GetName() const noexcept = 0;
  virtual void *operator() (std::vector<void*> const &, std::vector<void*> const &) const noexcept = 0;
};

template <typename ListType, typename ReturnType, typename... Types>
class Operation: public BasedOperation {
public:
  std::string const name;
  inline std::string const GetName() const noexcept override {
    return this->name;
  }
  inline void *operator() (std::vector<void*> const &args, std::vector<ListType*> const &list) const noexcept override {
    for(auto it = list.begin(); it != list.end(); ++it) {
      //if(!std::is_base_of<BasedOperation>(*it)) {
      //  throw *new std::string("Cannot evaluate!");
      //}
      if(
	 !it->GetName().compare(this->name) &&
	 TS::are_same(it->GetReturnType, *new ReturnType)
	 ) {
	return (*it)(args);
      }
    }
  }
  std::vector<ListType*> &list;
  Operation(std::vector<ListType*> &list):
    list(list) { };
};
