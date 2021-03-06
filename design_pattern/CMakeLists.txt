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
    "${DP_PUBLIC_INCLUDE_DIR}/simple_factory.h"
    "${DP_PUBLIC_INCLUDE_DIR}/strategy.h"
    "${DP_PUBLIC_INCLUDE_DIR}/decorator.h"
    "${DP_PUBLIC_INCLUDE_DIR}/proxy.h"
    "${DP_PUBLIC_INCLUDE_DIR}/factory_method.h"
    "${DP_PUBLIC_INCLUDE_DIR}/prototype.h"
    "${DP_PUBLIC_INCLUDE_DIR}/template_method.h"
    "${DP_PUBLIC_INCLUDE_DIR}/facade.h"
    "${DP_PUBLIC_INCLUDE_DIR}/builder.h"
    "${DP_PUBLIC_INCLUDE_DIR}/observer.h"
    "${DP_PUBLIC_INCLUDE_DIR}/abstract_factory.h"
    "${DP_PUBLIC_INCLUDE_DIR}/state.h"
    "${DP_PUBLIC_INCLUDE_DIR}/adapter.h"
    "${DP_PUBLIC_INCLUDE_DIR}/memento.h"
    "${DP_PUBLIC_INCLUDE_DIR}/composite.h"
    "${DP_PUBLIC_INCLUDE_DIR}/iterator.h"
    "${DP_PUBLIC_INCLUDE_DIR}/bridge.h"
    "${DP_PUBLIC_INCLUDE_DIR}/command.h"
    "${DP_PUBLIC_INCLUDE_DIR}/chain_of_responsibility.h"
    "${DP_PUBLIC_INCLUDE_DIR}/mediator.h"
    "${DP_PUBLIC_INCLUDE_DIR}/flyweight.h"
    "${DP_PUBLIC_INCLUDE_DIR}/interpreter.h"
    "${DP_PUBLIC_INCLUDE_DIR}/visitor.h"
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
        "${PROJECT_SOURCE_DIR}/util/SimpleSignal.h"

  
        "${test_file}"
    )
    target_link_libraries("${test_target_name}" hz)
  
    add_test(NAME "${test_target_name}" COMMAND "${test_target_name}")
  endfunction(dp_test)

  dp_test("${PROJECT_SOURCE_DIR}/src/singleton_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/factory_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/strategy_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/decorator_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/proxy_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/prototype_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/template_method_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/facade_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/builder_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/observer_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/state_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/adapter_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/memento_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/composite_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/iterator_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/bridge_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/command_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/chain_of_responsibility_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/mediator_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/flyweight_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/interpreter_test.cc")
  dp_test("${PROJECT_SOURCE_DIR}/src/visitor_test.cc")
endif(DP_BUILD_TESTS)

install(
  FILES

)