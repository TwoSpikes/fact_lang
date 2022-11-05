#pragma once

#include <string>

class BasedOperator {
public:
  virtual std::string &GetName() const noexcept = 0;
  virtual void operator() = 0;
};

template <typename ReturnType, typename... Types>
class Operator final: public BasedOperator {
private:
  const std::string name;
  ReturnType(*const algorithm)(Types...);
public:
  inline std::string &GetName() const noexcept override {
    return *new std::string(this->name);
  }
  inline Operator(std::string const name,
	          ReturnType(*algorithm)(Types...)):
    name(name), algorithm(algorithm) { }
};
