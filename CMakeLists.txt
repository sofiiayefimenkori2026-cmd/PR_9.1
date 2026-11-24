cmake_minimum_required(VERSION 3.15)
project(Lab_09 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source programs
# 9.1: Багатомодульний проєкт
add_executable(Lab_09_1 var.cpp dod.cpp sum.cpp Lab_09_1.cpp)

# 9.2.1: Гілка 1 (Z > 10) та Гілка 2 (Z <= 10)
add_executable(Lab_09_2_1_b1 Lab_09_2_1.cpp)
target_compile_definitions(Lab_09_2_1_b1 PRIVATE Z=15)

add_executable(Lab_09_2_1_b2 Lab_09_2_1.cpp)
target_compile_definitions(Lab_09_2_1_b2 PRIVATE Z=5)

# Testing
enable_testing()

add_executable(UnitTest_09_1 tests/UnitTest_09_1.cpp var.cpp dod.cpp sum.cpp)
target_include_directories(UnitTest_09_1 PRIVATE tests .)
add_test(NAME Test_09_1 COMMAND UnitTest_09_1)

add_executable(UnitTest_09_2_1 tests/UnitTest_09_2_1.cpp)
target_include_directories(UnitTest_09_2_1 PRIVATE tests .)
add_test(NAME Test_09_2_1 COMMAND UnitTest_09_2_1)
