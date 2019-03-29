cmake_minimum_required(VERSION 3.13)

project(leetcode)

include_directories(src/include)            #指定头文件目录

aux_source_directory(src/main dir_srcs)     #指定原始目录，不要忘记第二个参数dir_srcs

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)                 #指定编译类型为debug或release

set(leetcode ${./dir_srcs})                       #添加要编译的可执行文件。注意，通过变量WORK来编译

add_executable(leetcode ${leetcode})

