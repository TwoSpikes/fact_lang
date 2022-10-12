cmake_minimum_required(VERSION 3.10)

project(fact_lang)

set(YOUR_DIRECTORY ../src)

include_directories(include)

add_executable( fact_lang
  ../src/main.cpp
  ../src/lexer/parse_argv.cpp
  ../src/lexer/parse_one_argv.cpp
)
