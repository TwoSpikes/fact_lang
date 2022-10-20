cmake_minimum_required(VERSION 3.24)

project(fact_lang)

set(YOUR_DIRECTORY ../src)

include_directories(include)

add_executable( fact_lang
  ../src/main.cpp
  ../src/lexer/get_argv.cpp
  ../src/lexer/get_one_argv.cpp
  ../src/lexer/handle_argv.cpp
  ../src/lexer/handle_one_argv.cpp
  ../src/lexer/handle_option.cpp
  ../src/lexer/cut_until_equal.cpp
  ../src/lexer/cut_from_equal.cpp
)
