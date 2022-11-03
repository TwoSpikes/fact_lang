#pragma once

#include <string>

struct Operator {
public:
  std::string &GetName() const;
  Operator(std::string name);
protected:
  const std::string name;
};

template <typename ReturnType, typename... Types>
struct SpecificOperator final: public Operator {
public:
  std::string &GetName() const;
  ReturnType (*algorithm)(Types...);
  inline SpecificOperator(std::string name): Operator(name) { };
};
