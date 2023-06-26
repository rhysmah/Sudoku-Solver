//
// Created by Rhys Mahannah on 2023-06-24.
//
#ifndef SUDOKU_H
#define SUDOKU_H

#define SUDOKU_HORIZONTAL_SEPARATOR "-------------------------------\n"
#define SUDOKU_VERTICAL_SEPARATOR   "|"

extern int  UNSOLVED;
extern int  BOX_SIZE;
extern int  ROW_SIZE;
extern int  COLUMN_SIZE;

typedef struct Box {
    int    numbersInBox;
    int    solvable;
    int    possibleValues[9];
    struct SingleSquare ** squares;
    struct Box * next; // Points to the next Box object
} Box;

// Represents a 1x1 Sudoku square that holds a single value.
typedef struct SingleSquare
{
    int number;

    // Numbers -> [1] [1] [1] [1] [1] [1] [1] [1] [1]
    // Index   -> [9] [8] [7] [6] [5] [4] [3] [2] [1]
    int possibleValues[9];
    int solvable;

    int row;
    int column;

    Box * boxPosition;

} SingleSquare;

int checkPuzzle(SingleSquare *** puzzle);

int ** createPuzzle();

void printPuzzle(SingleSquare *** square);

SingleSquare *** setUpPuzzle(int ** puzzle);

int updateSudoku(SingleSquare *** sudoku, int row, int column);

Box ** createBoxes();

int updateBoxes(SingleSquare *** sudoku, int row, int column);

#endif
