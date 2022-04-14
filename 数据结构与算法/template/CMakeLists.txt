cmake_minimum_required(VERSION 3.21)
project(template)

set(CMAKE_CXX_STANDARD 11)

add_executable(template main.cpp UnionFind.cpp Kruskal.cpp Prim.cpp Dijkstra.cpp)
