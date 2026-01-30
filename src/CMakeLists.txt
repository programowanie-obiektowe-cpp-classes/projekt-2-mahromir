add_subdirectory(integrators)
add_subdirectory(forces)
add_subdirectory(utils)
add_subdirectory(propagation)
add_subdirectory(orbits)

add_executable(${EXEC_NAME} main.cpp)

target_link_libraries(${EXEC_NAME} PRIVATE integrators eigen_lib propagation)
# target_link_libraries(integrators Eigen::Eigen)


