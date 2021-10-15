# - Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - Output all cmomands by default for instructive purposes
set(CMAKE_VERBOSE_MAKEFILE ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

#- Set C++ standard directly
#set(CMAKE_CXX_STANDARD 14)

# - Declare build
add_executable(mpags-cipher mpags-cipher.cpp)

# - Use flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

# - Add in target compiler
target_compile_features(mpags-cipher 
    PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
    )