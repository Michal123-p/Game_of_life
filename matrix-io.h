#ifndef _MATRIX_IO_H
#define _MATRIX_IO_H

typedef struct Matrix {
	int row,col;
	int **data;

} Mat;

Mat *readFromFile(char *filename);

Mat* createMatrix(int row, int col);

void freeMatrix(Mat *mat);

void saveImage(Mat *mat);

#endif
