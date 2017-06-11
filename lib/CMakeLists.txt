aux_source_directory(. ROBOT_LIB)

add_library(robot_lib SHARED ${ROBOT_LIB})
target_link_libraries(robot_lib ${LIBSX_LIB} ${MATH_LIB})