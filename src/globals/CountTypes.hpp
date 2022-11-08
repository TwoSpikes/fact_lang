#pragma once

#include <type_traits>
#include <string>

template <typename... Types>
class CountTypes {
public:
  constexpr bool value(Types...) {
    throw *new std::string("Cannot evaluate!");
    return false;
  }
};

template <typename A, typename... B>
class CountTypes<A, std::tuple<B...>> {
public:
  constexpr int value() {
    return value<A, B...>();
  }
private:
  template <typename C>
  constexpr int value() {
    return 0;
  }
  
  template <typename C, typename... D>
  constexpr int value() {
    return value<D...>();
  }
};
