cmake_minimum_required(VERSION 3.0.0)

set (This Polynomial)
project (${This} CXX)


set(CMAKE_C_STANDART 99)
set(CMAKE_CXX_STANDART 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(tests)
add_subdirectory(sample)

include_directories("include")
include_directories("src")

set (Headers
  include/list.h
  include/polynomial.h
  include/monom.h
  include/polynomial-all.h
)

set(Sources
  src/monom.cpp
  src/polynomial.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})