set(NAME eigen_lib)
add_library(${NAME} INTERFACE)

set(EIGEN_URL https://gitlab.com/libeigen/eigen.git)
set(EIGEN_VERSION 3.4.0)

include(FetchContent)

# This is a tricky way to override the default Eigen3 target
# that is created by FetchContent. This custom target is not including
# any targets defined by the Eigen3 library, so not to create mess in the project.
FetchContent_Declare(
        Eigen3
        GIT_REPOSITORY ${EIGEN_URL}
        GIT_TAG        ${EIGEN_VERSION}
        GIT_SHALLOW TRUE
        SOURCE_SUBDIR dummy
)
FetchContent_MakeAvailable(Eigen3)

if(NOT TARGET Eigen3::Eigen)
    add_library(Eigen3::Eigen INTERFACE IMPORTED)
    # target_compile_definitions(Eigen3::Eigen INTERFACE EIGEN_NO_MALLOC)
    set_target_properties(Eigen3::Eigen PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${eigen3_SOURCE_DIR})
    target_link_libraries(${NAME} INTERFACE Eigen3::Eigen)
endif()