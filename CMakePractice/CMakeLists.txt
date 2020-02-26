cmake_minimum_required(VERSION 3.10)

# set the project name
project(cmakeLearning VERSION 0.1)

# options
option(USE_SRC "Use the src directory" ON)

if(USE_SRC)
    add_subdirectory(src)
    list(APPEND EXTRA_LIBS src)
endif()

# add a subdirectory
add_subdirectory(src)

# add the executable
add_executable(hello src/hello.cpp)

# header file to pass version number to source code
configure_file(src/helloConfig.h.in helloConfig.h)

target_include_directories(hello PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            )

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
