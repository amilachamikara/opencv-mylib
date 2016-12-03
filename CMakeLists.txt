cmake_minimum_required(VERSION 2.8)
project(opencv-mylib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package( OpenCV REQUIRED )
set(SOURCE_FILES main.cpp)
add_executable(opencv-mylib ${SOURCE_FILES})
target_link_libraries( opencv-mylib ${OpenCV_LIBS} )