#include "sudoku.h"

int  UNSOLVED    = 81;
int  BOX_SIZE    = 9;
int  ROW_SIZE    = 9;
int  COLUMN_SIZE = 9;

int main() {

    int ** sudokuPuzzle;
    SingleSquare *** sudoku;

    sudokuPuzzle = createPuzzle();

    sudoku = setUpPuzzle(sudokuPuzzle);

    printPuzzle(sudoku);

    checkPuzzle(sudoku);

    printPuzzle(sudoku);

    return 0;
}
