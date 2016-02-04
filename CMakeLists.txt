project(serialization_example)
cmake_minimum_required(VERSION 3.0)


set(CMAKE_CXX_FLAGS "-std=c++14 -g -O2")


set(SOURCE_FILES main.cpp)
add_executable(serialization_example ${SOURCE_FILES})

# Boost dependency
find_package(Boost COMPONENTS system REQUIRED)
find_package(Boost 1.58 REQUIRED system serialization)




TARGET_LINK_LIBRARIES(serialization_example ${Boost_LIBRARIES})
