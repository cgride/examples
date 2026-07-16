cmake_minimum_required(VERSION 3.22)

project(
  cgride-embedded-api-example
  VERSION 0.1.0
  DESCRIPTION "Embedded API example for Cgride."
  LANGUAGES CXX
)

find_package(cgride CONFIG REQUIRED)

add_executable(cgride_embedded_api_example
  src/main.cpp
)

target_compile_features(cgride_embedded_api_example
  PRIVATE
    cxx_std_23
)

target_link_libraries(cgride_embedded_api_example
  PRIVATE
    cgride::cgride
)

set_target_properties(cgride_embedded_api_example
  PROPERTIES
    CXX_EXTENSIONS OFF
)
