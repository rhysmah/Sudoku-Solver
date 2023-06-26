//
// Created by Rhys Mahannah on 2023-06-25.
//
#include "sudoku.h"

#ifndef SUDOKUSOLVER_SQUARE_H
#define SUDOKUSOLVER_SQUARE_H

#endif //SUDOKUSOLVER_SQUARE_H

int solveSquare(SingleSquare * square) {

    int i;

    for (i = 0; i < COLUMN_SIZE; ++i) {
        if (square -> possibleValues[i] == 0) {
            square -> number = i + 1;
            square -> solvable = 0;
            UNSOLVED--;
        }
    }
    return 1;
}
