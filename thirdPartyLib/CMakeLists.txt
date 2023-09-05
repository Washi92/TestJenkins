cmake_minimum_required(VERSION 3.13)
project(studentLib)

add_library(studentLib INTERFACE)
target_include_directories(studentLib INTERFACE  "${CMAKE_CURRENT_SOURCE_DIR}")

#Define MY_SOURCES to be a list of all the source files for my game 
#file(GLOB_RECURSE STUDENT_LIB_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
#add_executable(studentLib_test)
#target_sources(studentLib_test PRIVATE ${STUDENT_LIB_SOURCES} )
#target_link_libraries(studentLib_test PUBLIC studentLib)
