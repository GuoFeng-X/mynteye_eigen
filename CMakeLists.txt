cmake_minimum_required(VERSION 2.8)
project(eigen_test)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g")

find_package(OpenCV REQUIRED)

find_package(Eigen3)
include_directories( ${EIGEN3_INCLUDE_DIR})

add_executable(main main.cpp)

target_link_libraries(main ${OpenCV_LIBS})