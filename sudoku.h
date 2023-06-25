//
// Created by Rhys Mahannah on 2023-06-24.
//
#ifndef SUDOKU_H
#define SUDOKU_H

#define SUDOKU_HORIZONTAL_SEPARATOR "-------------------------------\n"
#define SUDOKU_VERTICAL_SEPARATOR   "|"

extern char POSSIBLE_VALUES;
extern int  BOX_SIZE;
extern int  ROW_SIZE;
extern int  COLUMN_SIZE;

typedef struct Box
{

    struct Box * next;
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

int ** createPuzzle();

void printPuzzle(int ** puzzle);

SingleSquare *** setUpPuzzle(int ** puzzle);

int updateSudoku(SingleSquare *** sudoku, int row, int column);

#endif
