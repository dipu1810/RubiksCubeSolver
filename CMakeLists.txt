cmake_minimum_required(VERSION 3.28)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCubeSolver
        RubiksCube.cpp
        RubiksCube.h
        RubiksCube3darr.cpp
        RubiksCube3darr.h
        BFSSolver.cpp
        BFSSolver.h
        IDDFSSolver.cpp
        IDDFSSolver.h
        math.cpp
        math.h
        main.cpp
        PermutationIndexer.h
        PatternDatabase.cpp
        PatternDatabase.h
        NibbleArray.cpp
        NibbleArray.h
        CornerPatternDatabase.cpp
        CornerPatternDatabase.h
        CornerDBMaker.cpp
        CornerDBMaker.h
)
