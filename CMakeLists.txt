cmake_minimum_required(VERSION 3.20)
set(EXEC_NAME cpp-project)
project(${EXEC_NAME} CXX)

file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${EXEC_NAME} ${SRC_FILES})
target_include_directories(${EXEC_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")
set_target_properties(${EXEC_NAME} PROPERTIES CXX_STANDARD 23)
if(MINGW)
  target_link_libraries(${EXEC_NAME} "-lstdc++exp")
endif()

add_subdirectory(libs)
target_link_libraries(${EXEC_NAME} PRIVATE eigen_lib)