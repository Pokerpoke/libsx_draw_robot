project(robot)

cmake_minimum_required(VERSION 2.6)

#######################################################
# include directories
#######################################################
include_directories(
    ${CMAKE_SOURCE_DIR}/lib
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/lib
    ${CMAKE_BINARY_DIR}/include
)


#######################################################
# sbdirectory
#######################################################
add_subdirectory(app)
add_subdirectory(lib)