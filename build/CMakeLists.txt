cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDART 20)

project(fact_lang)

set(YOUR_DIRECTORY ../src)

set(SOURCE_FILES
  ../src/main.cpp
  ../src/lexer/get_argv.cpp
  ../src/lexer/get_one_argv.cpp
  ../src/lexer/handle_argv.cpp
  ../src/lexer/handle_one_argv.cpp
  ../src/lexer/GetOptionValue.cpp
  ../src/lexer/GetOptionName.cpp
  ../src/lexer/handle_option.cpp
  ../src/lexer/handle_option_d.cpp
  ../src/lexer/cut_until_equal.cpp
  ../src/lexer/cut_from_equal.cpp
  ../src/lexer/str_to_bool.cpp
  ../src/lexer/handle_filename.cpp
  ../src/parser/HandleFile.cpp
  ../src/parser/MarkStatements.cpp
  ../src/parser/ToOperators.cpp
)

include_directories(include)

add_executable( fact_lang
  ${SOURCE_FILES}
)
