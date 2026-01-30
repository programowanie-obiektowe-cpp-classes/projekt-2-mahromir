set(NAME integrators)

add_library(${NAME} STATIC)

target_sources(${NAME}
    PRIVATE
        src/rk4.cpp
)

# Expose include directory to anything linking against this library
target_include_directories(${NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${NAME} 
    forces
    utils
    eigen_lib
)
