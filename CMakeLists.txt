cmake_minimum_required(VERSION 3.22)

project(
  cgride-examples
  VERSION 0.1.0
  DESCRIPTION "Example projects for Cgride."
  HOMEPAGE_URL "https://github.com/cgride/examples"
  LANGUAGES CXX
)

option(CGRIDE_EXAMPLES_BUILD_EMBEDDED_API "Build the embedded API example" ON)
option(CGRIDE_EXAMPLES_ENABLE_CGRIDE_TARGETS "Add helper targets that call the cgride CLI examples" OFF)

if(CGRIDE_EXAMPLES_BUILD_EMBEDDED_API)
  add_subdirectory(embedded-api)
endif()

if(CGRIDE_EXAMPLES_ENABLE_CGRIDE_TARGETS)
  find_program(CGRIDE_EXECUTABLE cgride)

  if(CGRIDE_EXECUTABLE)
    add_custom_target(cgride_example_hello
      COMMAND ${CGRIDE_EXECUTABLE} build
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/hello
      COMMENT "Building hello example with cgride"
      VERBATIM
    )

    add_custom_target(cgride_example_static_library
      COMMAND ${CGRIDE_EXECUTABLE} build
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/static-library
      COMMENT "Building static-library example with cgride"
      VERBATIM
    )

    add_custom_target(cgride_example_multiple_targets
      COMMAND ${CGRIDE_EXECUTABLE} build
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/multiple-targets
      COMMENT "Building multiple-targets example with cgride"
      VERBATIM
    )

    add_custom_target(cgride_examples_cli
      DEPENDS
        cgride_example_hello
        cgride_example_static_library
        cgride_example_multiple_targets
    )
  else()
    message(WARNING "cgride executable was not found. CLI example targets will not be available.")
  endif()
endif()
