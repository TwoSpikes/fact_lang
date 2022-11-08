#pragma once

#include <algorithm>

#include "./rust_types.h"

template<size_t N>
struct StringLiteral {
    inline constexpr StringLiteral(const char (&str)[N]) {
        std::copy_n(str, N, value);
    }
    
    char value[N];
};
