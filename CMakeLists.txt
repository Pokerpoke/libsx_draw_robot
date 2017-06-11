project(robot)

cmake_minimum_required(VERSION 2.6)

#######################################################
# Find libraries
#######################################################

find_library(LIBSX_LIB sx)
find_library(MATH_LIB m)

#######################################################
# Include directories
#######################################################
include_directories(
    ${CMAKE_SOURCE_DIR}/lib
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/lib
    ${CMAKE_BINARY_DIR}/include
)


#######################################################
# Sub directories
#######################################################
add_subdirectory(app)
add_subdirectory(lib)

