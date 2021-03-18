#ifndef _MATRIX_IO_H
#define _MATRIX_IO_H

#include <stdio.h>

#include "matrix-action.h"


Mat *readFromFile(char *filename);

void writeMatrix(FILE *out, Mat *mat);

void saveImage(FILE *out, Mat *mat);
#endif
