cmake_minimum_required(VERSION 3.10)
project(graph)

set(CMAKE_CXX_STANDARD 11)

add_executable(graph main.cpp digraph.cpp digraph.h edge.cpp edge.h graph.cpp graph.h undirgraph.cpp undirgraph.h ConectedComponents.cpp ConectedComponents.h Lowest_Cost_Walk.cpp Lowest_Cost_Walk.h DAG.cpp DAG.h)