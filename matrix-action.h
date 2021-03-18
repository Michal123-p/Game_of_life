#ifndef _MATRIX_ACTION_H
#define _MATRIX_ACTION_H

#include <stdio.h>

typedef struct Matrix {
    int row,col;
    int **data;

} Mat;

Mat* createMatrix(int r, int c);

void freeMatrix(Mat *mat);

int compare (Mat *mat1, Mat *mat2);

#endif
