cmake_minimum_required(VERSION 3.15)

set (This TESTS)

set (Sources
  test_list.cpp
  test_monom.cpp
  test_polynomial.cpp
)

include_directories("../include")
include_directories("../src")


add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
  gtest_main
  Polynomial
)

add_test(
  NAME ${This}
  COMMAND ${This}
)