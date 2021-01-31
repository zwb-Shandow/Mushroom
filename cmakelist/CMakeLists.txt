# 1.cmake version,指定cmake版本
cmake_minimum_required(VERSION 3.5)

# 2.project name,指定项目的名称，一般和项目的文件夹名称对应
PROJECT(cmakelist)

# 3.head file path,头文件目录
INCLUDE_DIRECTORIES(include)

# 4.source directory,源文件目录
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

# 5.set environment variable，设置环境变量，编译用到的源文件全部都要放到这里，否则编译随能通过，但是执行时会出现问题
set(test_math ${DIR_SRCS})

# 6.add executable file,添加要编译的可执行文件
add_executable(${PROJECT_NAME} ${test_math})

# 7.add link library,添加可执行文件所需要的库
target_link_libraries(${PROJECT_NAME})