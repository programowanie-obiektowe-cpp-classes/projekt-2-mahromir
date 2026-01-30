set(NAME propagation)

add_library(${NAME} STATIC)

target_sources(${NAME}
    PRIVATE
        src/SpacecraftState.cpp
)

# Expose include directory to anything linking against this library
target_include_directories(${NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${NAME} 
    utils 
    eigen_lib
)