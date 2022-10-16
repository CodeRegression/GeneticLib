#--------------------------------------------------------
# Top-Level: GeneticLib
#
# @author: Wild Boar
#
# @Date Created: 2022-02-07
#--------------------------------------------------------

cmake_minimum_required(VERSION 3.0.0)
project(GeneticLibLib VERSION 0.1.0)

enable_testing()

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(GeneticLib)
add_subdirectory(GeneticLibTests)

