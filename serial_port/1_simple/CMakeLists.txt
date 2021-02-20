cmake_minimum_required(VERSION 3.1)
project(TEST)

## Target
set(CMAKE_CXX_STANDARD 11)
set(TEST_SRCS main.cpp)
add_executable(simple ${TEST_SRCS})

## Link librarys
set(BOOST_LIBS data_time_system)
find_package(Boost COMPONMENTS ${BOOST_LIBS} REQUIRED)
target_link_libraries(simple ${Boost_LIBRARIES})
find_package(Threads REQUIRED)
target_link_libraries(simple ${CMAKW_THREAD_LIBS_INIT})