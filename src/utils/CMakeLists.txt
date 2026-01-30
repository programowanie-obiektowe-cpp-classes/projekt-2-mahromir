set(NAME utils)

add_library(${NAME} STATIC)

target_sources(${NAME} PRIVATE 
    src/Constants.cpp
    src/AbsoluteDate.cpp
)


target_include_directories(${NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

