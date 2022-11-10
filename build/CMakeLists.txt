cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 20)

project(fact_lang)

set(YOUR_DIRECTORY ../src)

set(SOURCE_FILES
  ../src/main.cpp

  ../src/globals/CountTypes.hpp
  ../src/globals/StringLiteral.hpp
  ../src/globals/are_same.hpp
  
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
  ../src/parser/Operator.cpp
  ../src/parser/Operation.cpp
  ../src/parser/ParseAs<BasedOperator>.cpp
  ../src/parser/ParseAs<u8>.cpp
  ../src/parser/ParseAs.hpp
  ../src/parser/Parse.cpp
)

include_directories(include)

add_executable( fact_lang
  ${SOURCE_FILES}
)
