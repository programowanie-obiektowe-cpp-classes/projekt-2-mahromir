cmake_minimum_required(VERSION 3.10)

# Project name and C++ standard
project(Integrator VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# find_package(Eigen REQUIRED)

set(EXEC_NAME "app")

add_subdirectory(libs)
add_subdirectory(src)



