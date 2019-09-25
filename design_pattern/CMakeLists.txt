cmake_minimum_required(VERSION 3.9)

project(DP)

option(DP_BUILD_TESTS "Build DP's unit tests" ON)
set(DP_PUBLIC_INCLUDE_DIR "include/")

# 编译器用来寻找include文件的目录
include_directories (
  "${PROJECT_SOURCE_DIR}/include"
  "${PROJECT_SOURCE_DIR}/util"
  "${PROJECT_SOURCE_DIR}"
)


add_library(hz "")
target_sources(hz
  PRIVATE
    "${PROJECT_SOURCE_DIR}/src/singleton.cc"
    "${DP_PUBLIC_INCLUDE_DIR}/singleton.h"
    "${DP_PUBLIC_INCLUDE_DIR}/barrier.h"
)

if(DP_BUILD_TESTS)
  # enable_testing()
  function(dp_test test_file)
    get_filename_component(test_target_name "${test_file}" NAME_WE)
  
    add_executable("${test_target_name}" "")
    target_sources("${test_target_name}"
      PRIVATE
        "${PROJECT_SOURCE_DIR}/util/testharness.cc"
        "${PROJECT_SOURCE_DIR}/util/testharness.h"
        "${PROJECT_SOURCE_DIR}/util/basic.h"

  
        "${test_file}"
    )
    target_link_libraries("${test_target_name}" hz)
  
    add_test(NAME "${test_target_name}" COMMAND "${test_target_name}")
  endfunction(dp_test)

  dp_test("${PROJECT_SOURCE_DIR}/src/singleton_test.cc")
endif(DP_BUILD_TESTS)

install(
  FILES

)