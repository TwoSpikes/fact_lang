cmake_minimum_required(VERSION 3.10)

project(fact_lang)

set(YOUR_DIRECTORY ../src)

#add_executable(fact_lang ${YOUR_DIRECTORY}/main.cpp)

#target_include_directories(fact_lang PRIVATE $(YOUR_DIRECTORY)/parser)

#set(SOURCES ${YOUR_DIRECTORY}/parser/parse_argv.cpp ${YOUR_DIRECTORY}/parser/parse_argv.cpp)
#add_executable(fact_lang2 ${SOURCES})


include_directories(include)

add_executable(fact_lang
  ../src/main.cpp
  ../src/parser/parse_argv.hpp
  ../src/parser/parse_argv.cpp
)
