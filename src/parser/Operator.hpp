#pragma once

#include <string_view>
#include <stdarg.h>
#include <utility>

#include "../globals/rust_types.h"
#include "../globals/StringLiteral.hpp"

class BasedOp { };

class BasedOperator: public BasedOp {
public:
  virtual void* operator() (std::vector<void*> const &) const noexcept = 0;
  constexpr static const StringLiteral GetName = "NULL";
};

template <StringLiteral name,
	  typename ReturnType,
	  typename... Types>
class Operator final: public BasedOperator {
private:
  ReturnType*(*const algorithm)(std::vector<void*> const &);
public:
  void* operator() (std::vector<void*> const &args) const noexcept override {
    return this->algorithm(args);
  }
  
  inline Operator(ReturnType*(*algorithm)(std::vector<void*> const &)):
    algorithm(algorithm) { }
  
  constexpr static const auto GetName = name;
  static ReturnType GetReturnType;
};
