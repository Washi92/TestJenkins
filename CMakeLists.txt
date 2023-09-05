cmake_minimum_required(VERSION 3.13)

add_subdirectory("thirdPartyLib")

project(appMain)
set(CMAKE_CXX_STANDARD 17)
add_executable(appMain "src/main.cpp" "thirdPartyLib/src/main.cpp" "thirdPartyLib/includeLib/functions.h")
target_include_directories(appMain PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(appMain PRIVATE studentLib)