cmake_minimum_required(VERSION 3.15)
project(proj2_Summer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj2_Summer
        BinarySearchTree.h
        Driver.cpp
        dsexceptions.h
        Exceptions.h
        Indexer.cpp
        Indexer.h
        Word.cpp
        Word.h)
