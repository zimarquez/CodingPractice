add_library(src calculator.cpp)

target_include_directories(src
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )
