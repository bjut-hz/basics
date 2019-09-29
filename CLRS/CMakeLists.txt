cmake_minimum_required(VERSION 3.9)

project(CLRS)

option(CLRS_BUILD_TESTS "Build CLRS's unit tests" ON)
set(CLRS_PUBLIC_INCLUDE_DIR "include/")

# 编译器用来寻找include文件的目录
include_directories (
  "${PROJECT_SOURCE_DIR}/include"
  "${PROJECT_SOURCE_DIR}/util"
  "${PROJECT_SOURCE_DIR}"
)


add_library(hz "")
target_sources(hz
  PRIVATE
    "${PROJECT_SOURCE_DIR}/src/sort.cc"
    "${CLRS_PUBLIC_INCLUDE_DIR}/sort.h"
    "${CLRS_PUBLIC_INCLUDE_DIR}/maximum_subarray.h"
    "${CLRS_PUBLIC_INCLUDE_DIR}/square_matrix_multiply.h"
    "${CLRS_PUBLIC_INCLUDE_DIR}/hire_assistant.h"
    "${CLRS_PUBLIC_INCLUDE_DIR}/heap.h"
    "${CLRS_PUBLIC_INCLUDE_DIR}/list.h"
    "${CLRS_PUBLIC_INCLUDE_DIR}/order_statistic.h"
    "${CLRS_PUBLIC_INCLUDE_DIR}/stack.h"
    "${CLRS_PUBLIC_INCLUDE_DIR}/queue.h"
    "${CLRS_PUBLIC_INCLUDE_DIR}/hash.h"
    "${CLRS_PUBLIC_INCLUDE_DIR}/binary_search_tree.h"
    "${CLRS_PUBLIC_INCLUDE_DIR}/redblack.h"
)

if(CLRS_BUILD_TESTS)
  # enable_testing()
  function(clrs_test test_file)
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
  endfunction(clrs_test)

  clrs_test("${PROJECT_SOURCE_DIR}/src/sort_test.cc")
  clrs_test("${PROJECT_SOURCE_DIR}/src/maximum_subarray_test.cc")
  clrs_test("${PROJECT_SOURCE_DIR}/src/square_matrix_multiply_test.cc")
  clrs_test("${PROJECT_SOURCE_DIR}/src/hire_assistant_test.cc")
  clrs_test("${PROJECT_SOURCE_DIR}/src/heap_test.cc")
  clrs_test("${PROJECT_SOURCE_DIR}/src/list_test.cc")
  clrs_test("${PROJECT_SOURCE_DIR}/src/order_statistic_test.cc")
  clrs_test("${PROJECT_SOURCE_DIR}/src/stack_test.cc")
  clrs_test("${PROJECT_SOURCE_DIR}/src/queue_test.cc")
  clrs_test("${PROJECT_SOURCE_DIR}/src/hash_test.cc")
  clrs_test("${PROJECT_SOURCE_DIR}/src/binary_search_tree_test.cc")
  clrs_test("${PROJECT_SOURCE_DIR}/src/redblack_test.cc")
endif(CLRS_BUILD_TESTS)

install(
  FILES
)