#pragma once

#include <type_traits>
#include <vector>
#include <string>

#include "../globals/CountTypes.hpp"
#include "../globals/are_same.hpp"

class BasedOperation {
public:
  virtual std::string const GetName() const noexcept = 0;
};

class BasedConstOperation: public BasedOperation {
public:
  virtual void *GetVal() const noexcept = 0;
};

class BasedOperatorOperation: public BasedOperation {
public:
  virtual std::vector<BasedConstOperation *> &GetSrc() const noexcept = 0;
};

//plain numbers
template <typename T>
class ConstOperation final: public BasedConstOperation {
private:
  T *val;
  std::string const name;
public:
  inline std::string const GetName() const noexcept override final {
    return this->name;
  }
  inline void *GetVal() const noexcept override final {
    return this->val;
  }
  inline ConstOperation(T val): val(new T(val)) { }
};

class OperatorOperation final: public BasedOperatorOperation {
private:
  std::vector<BasedConstOperation *> src;
  std::string const name;
public:
  inline std::string const GetName() const noexcept override final {
    return this->name;
  }
  inline std::vector<BasedConstOperation *> &GetSrc() const noexcept override final {
    return *new std::vector<BasedConstOperation *>(this->src);
  }
  inline OperatorOperation(std::vector<BasedConstOperation *> src):
    src(src) { };
};
