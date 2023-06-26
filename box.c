//
// Created by Rhys Mahannah on 2023-06-26.
//
#include <stdlib.h>
#include "sudoku.h"

Box ** createBoxes() {

    int i, j;
    Box ** boxes;
    boxes = malloc(sizeof(Box *) * 9);

    for (i = 0; i < 9; ++i) {

        boxes[i] = malloc(sizeof(Box));

        boxes[i] -> squares      = malloc(sizeof(SingleSquare *) * 9);
        boxes[i] -> numbersInBox = 0;
        boxes[i] -> solvable     = 9;

        for (j = 0; j < 9; ++j) {
            boxes[i] -> possibleValues[j] = 0;
        }
    }
    return boxes;
}

int updateBoxes(SingleSquare *** sudoku, int row, int column){

    int i;
    int number = sudoku[row][column] -> number;

    Box * box;
    box = sudoku[row][column] -> boxPosition;

    for (i = 0; i < 9; ++i) {
        if (box -> squares[i] -> possibleValues[number - 1] == 0) {
            box -> squares[i] -> solvable--;
            box -> squares[i] -> possibleValues[number - 1] = 1;
        }
    }
}