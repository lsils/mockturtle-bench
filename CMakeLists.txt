cmake_minimum_required(VERSION 3.8)

project(mockturtle-bench LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(ABC_USE_NAMESPACE "abc")
add_subdirectory(abc)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Enable testing of the benchmark library." FORCE)
add_subdirectory(benchmark)
add_subdirectory(mockturtle)

add_subdirectory(src)
