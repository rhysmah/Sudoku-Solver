#include "sudoku.h"

char POSSIBLE_VALUES = 0x1FF;
int  BOX_SIZE        = 9;
int  ROW_SIZE        = 9;
int  COLUMN_SIZE     = 9;

int main() {

    int ** sudokuPuzzle;
    SingleSquare *** sudoku;

    sudokuPuzzle = createPuzzle();

    printPuzzle(sudokuPuzzle);

    sudoku = setUpPuzzle(sudokuPuzzle);

    return 0;
}
