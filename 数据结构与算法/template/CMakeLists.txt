cmake_minimum_required(VERSION 3.21)
project(template)

set(CMAKE_CXX_STANDARD 11)

add_executable(template main.cpp UnionFind.cpp Kruskal.cpp Prim.cpp)
add_executable(743 leetcodeDebug/743.cpp)
add_executable(1514 ./leetcodeDebug/1514.cpp)
add_executable(886 ./leetcodeDebug/886.cpp)