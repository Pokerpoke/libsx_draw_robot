add_executable(robot robot.c)
target_link_libraries(robot robot_lib ${LIBSX_LIB})