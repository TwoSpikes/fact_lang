#pragma once

#include <string>
#include <utility>
#include <typeinfo>

#include "../globals/rust_types.h"
#include "../globals/StringLiteral.hpp"

class BasedOp { };

class BasedOperator: public BasedOp {
public:
  virtual void *operator() (std::vector<void*> const &) const noexcept = 0;
  virtual std::string const &GetName() const noexcept = 0;
  virtual std::type_info const &GetReturnType() const noexcept = 0;
};

template <typename ReturnType,
	  typename... Types>
class Operator final: public BasedOperator {
private:
  ReturnType*(*const algorithm)(std::vector<void*> const &);
  std::string const name;
public:
  typedef BasedOperator super;
  void* operator() (std::vector<void*> const &args) const noexcept override {
    return this->algorithm(args);
  }
  inline Operator(std::string const &name,
		  ReturnType*(*algorithm)(std::vector<void*> const &)):
    name(name), algorithm(algorithm) { }
  inline std::string const &GetName() const noexcept override {
    return name;
  }
  inline std::type_info const &GetReturnType() const noexcept override {
    return { typeid(name) };
  }
};
