#pragma once

#include <type_traits>
#include <vector>
#include <string>

#include "../globals/CountTypes.hpp"
#include "../globals/are_same.hpp"

class BasedOperation {
public:
  virtual std::string const GetName() const noexcept = 0;
  inline virtual void *operator() (std::vector<void*> const &, std::vector<void*> const &) const {
    throw -1;
  }
  inline virtual void *operator() () const {
    throw -1;
  }
};

template <typename T>
class ConstOperation: public BasedOperation {
private:
  T *val;
  std::string const name;
public:
  inline std::string const GetName() const noexcept override {
    return this->name;
  }
  inline virtual void *operator() () const override {
    return this->val;
  }
  inline ConstOperation(T &val): val(new T(val)) { }
  inline ConstOperation(T *val): val(val) { }
};

template <typename ListType, typename ReturnType, typename... Types>
class Operation: public BasedOperation {
private:
  std::vector<ListType*> &list;
  std::string const name;
public:
  inline std::string const GetName() const noexcept override {
    return this->name;
  }
  inline void *operator() (std::vector<void*> const &args, std::vector<ListType*> const &list) const override {
    for(auto it = list.begin(); it != list.end(); ++it) {
      if(
	 !it->GetName().compare(this->name) &&
	 TS::are_same(it->GetReturnType, *new ReturnType)
	 ) {
	return (*it)(args);
      }
    }
  }
  inline Operation(std::vector<ListType*> &list):
    list(list) { };
};
