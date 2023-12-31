//
// Created by Rhys Mahannah on 2023-06-24.
//
#include <stdlib.h>
#include <stdio.h>

#include "sudoku.h"
#include "square.h"


/*
 * Creates an array of
 */
SingleSquare *** setUpPuzzle(int ** puzzle) {

    int i, j, k;
    int currentBox = 0;
    Box ** boxes;
    SingleSquare *** sudoku;

    sudoku = (SingleSquare ***) malloc(sizeof(SingleSquare**) * COLUMN_SIZE);
    boxes  = createBoxes();

    // Loop through Sudoku rows
    for (i = 0; i < COLUMN_SIZE; ++i) {

        sudoku[i] = (SingleSquare **)malloc(sizeof(SingleSquare *) * ROW_SIZE);

        // Loop through Sudoku columns
        for (j = 0; j < ROW_SIZE; ++j) {

            sudoku[i][j] = (SingleSquare *)malloc(sizeof(SingleSquare));

            // Assign Sudoku box value, row position, and column positions
            sudoku[i][j] -> number   = puzzle[i][j]; // Integer value at this index position in 2D array
            sudoku[i][j] -> row      = i;            // Row position of box
            sudoku[i][j] -> column   = j;            // Column position of box
            sudoku[i][j] -> solvable = 9;

            boxes[currentBox] -> squares[ boxes[currentBox] -> numbersInBox] = sudoku[i][j];
            sudoku[i][j] -> boxPosition = boxes[currentBox];
            boxes[currentBox] -> numbersInBox++;

            // Initialize all values in "possibleValues" array to 0
            for (k = 0; k < BOX_SIZE; ++k) {
                sudoku[i][j] -> possibleValues[k] = 0;
            }
            if (j == 2) {
                ++currentBox;
            }
            if (j == 5) {
                ++currentBox;
            }
        }
        currentBox -= 2;
        if (i == 2) {
            currentBox = 3;
        }
        if (i == 5) {
            currentBox = 6;
        }
    }

    /*
     * Above, we created our puzzle and assigned values to all Square structs.
     * (The Square structs represent each of the 81 squares in Sudoku.)
     *
     * Here, we're now looping through
     *
     */
    for (i = 0; i < COLUMN_SIZE; ++i) {
        for (j = 0; j < ROW_SIZE; ++j) {

            // If the value is NOT zero, then it is NOT solvable.
            if (sudoku[i][j] -> number != 0) {
                sudoku[i][j] -> solvable = 0;
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }
    return sudoku;
}

int updateSudoku(SingleSquare *** sudoku, int row, int column) {

    int i, j;
    int indexNumber = sudoku[row][column] -> number;

    // Loop through all rows
    for (i = 0; i < ROW_SIZE; ++i) {
        if (sudoku[i][column] -> possibleValues[indexNumber - 1] == 0) {
            sudoku[i][column] -> solvable--;
        }
        sudoku[i][column] -> possibleValues[indexNumber - 1] = 1;
    }

    for (j = 0; j < COLUMN_SIZE; ++j) {
        if (sudoku[row][j] -> possibleValues[indexNumber - 1] == 0) {
            sudoku[row][j] -> solvable--;
        }
        sudoku[row][j] -> possibleValues[indexNumber - 1] = 1;
    }
    return 1;
}

int checkPuzzle(SingleSquare *** puzzle) {
    int i, j;

    for (i = 0; i < ROW_SIZE; ++i) {
        for (j = 0; j < COLUMN_SIZE; ++j) {
            if (puzzle[i][j] -> solvable == 1) {
                solveSquare(puzzle[i][j]);
                updateSudoku(puzzle, i, j);
                updateBoxes(puzzle, i, j);
            }
        }
    }
    return 1;
}

int ** createPuzzle() {

    int ** puzzle; // Returns a double-pointer
    int i, j;      // Loop counters

    // Hard-coded Sudoku board; this is the original puzzle.
    int sudokuPuzzle[9][9] = {0, 1, 9,    0, 0, 2,    0, 0, 0,
                              4, 7, 0,    6, 9, 0,    0, 0, 1,
                              0, 0, 0,    4, 0, 0,    0, 9, 0,

                              8, 9, 4,    5, 0, 7,    0, 0, 0,
                              0, 0, 0,    0, 0, 0,    0, 0, 0,
                              0, 0, 0,    2, 0, 1,    9, 5, 8,

                              0, 5, 0,    0, 0, 6,    0, 0, 0,
                              6, 0, 0,    0, 2, 8,    0, 7, 9,
                              0, 0, 0,    1, 0, 0,    8, 6, 0};

    /*
     * Create a pointer, "puzzle", which points to the first element
     * in an sudokuPuzzle of nine integer pointers.
     */
    puzzle = (int**)malloc(sizeof(int*) * 9);

    /*
     * Loop through each integer pointer and dynamically allocate
     * memory for a nine-element integer array. This array will
     * represent one of nine 9x9 boxes in the Sudoku board.
     */
    for (i = 0; i < 9; ++i) {
        puzzle[i] = (int*)malloc(sizeof(int) * 9);

        /*
         * Loop through each integer in the integer sudokuPuzzle and assign it
         * a value from the equivalent position in the "sudokuPuzzle" Sudoku.
         */
        for (j = 0; j < 9; ++j) {
            puzzle[i][j] = sudokuPuzzle[i][j];
        }
    }
    return puzzle;
}

void printPuzzle(SingleSquare *** square)
{
    int i, j; // Loop counters

    // Go through each integer pointer
    printf("%s", SUDOKU_HORIZONTAL_SEPARATOR);
    for (i = 0; i < 9; ++i)
    {

        // Print each row of puzzle
        printf("%s", SUDOKU_VERTICAL_SEPARATOR);
        for (j = 0; j < 9; ++j)
        {

            printf(" %d ", square[i][j] -> number);

            // Separate each 3x3 with space
            if ((j + 1) % 3 == 0) {
                printf("%s", SUDOKU_VERTICAL_SEPARATOR);
            }
        }

        printf("\n");

        // Separate each 3x3 row with space
        if ((i + 1) % 3 == 0) {
            printf("%s", SUDOKU_HORIZONTAL_SEPARATOR);
        }
    }
}
