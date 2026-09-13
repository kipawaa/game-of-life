cmake_minimum_required(VERSION 3.14)
project(GoLTests LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(gol_tests
  TestStability.cpp
  TestCell.cpp
  TestBoardStep.cpp
  TestBoardInit.cpp
)

target_link_libraries(gol_tests
    PRIVATE
    cells
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(gol_tests)
