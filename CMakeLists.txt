cmake_minimum_required(VERSION 3.28)
project(RubiksCubeSolverExplain)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCubeSolverExplain main.cpp
        Model/RubiksCube.cpp
        Model/RubiksCube.h
        Model/RubiksCube3DArray.cpp
        Model/RubiksCube1DArray.cpp
        Solver/DFSSolver.h
        Solver/BFSSolver.h
        Solver/IDDFSSolver.h
        Solver/IDAstarSolver.h
)
