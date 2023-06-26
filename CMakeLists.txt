cmake_minimum_required(VERSION 3.24)
project(SudokuSolver C)

set(CMAKE_C_STANDARD 99)

add_executable(SudokuSolver main.c sudoku.h puzzle.c square.h box.c)
