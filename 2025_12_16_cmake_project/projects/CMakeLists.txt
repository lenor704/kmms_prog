cmake_minimum_required(VERSION 3.2...3.27.5)

project(cmake)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(sort)
add_subdirectory(obuchaika)

set(CMAKE_SUPPRESS_REGENERATION true)