cmake_minimum_required(VERSION 3.0.0)

set (This sample)
project (${This})

include_directories("../include")
add_executable(${This}
  sample.cpp
)

target_link_libraries(${This} PUBLIC
  Polynomial
)
