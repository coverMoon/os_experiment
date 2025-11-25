cmake_minimum_required(VERSION 3.20)
project(ProcessScheduler)

# 设置 c++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 头文件包含
include_directories(src)

# 源文件列表
set(SOURCE_FILES
    src/main.cpp
    src/Scheduler.cpp
)

# 生成可执行文件
add_executable(ProcessScheduler ${SOURCE_FILES})
