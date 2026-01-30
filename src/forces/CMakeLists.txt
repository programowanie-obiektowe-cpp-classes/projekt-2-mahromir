set(NAME forces)

# Create a static library from rk4.cpp
add_library(${NAME} STATIC)

target_sources(${NAME}
    PRIVATE
        src/ForceModel.cpp
)

# Expose include directory to anything linking against this library
target_include_directories(${NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${NAME} utils eigen_lib)