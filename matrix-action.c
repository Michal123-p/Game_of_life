#include <stdlib.h>

#include "matrix-action.h"

Mat* createMatrix(int r, int c) {
    int i;
    Mat *mat = (Mat*) malloc(sizeof(Mat));
    if(mat != NULL) {
        mat->row = r;
        mat->col = c;
        mat->data = (int**) malloc(sizeof(int*) * r);
        for(i=0; i<r;i++)
            mat->data[i] = (int*) malloc(sizeof(int) * c);
    }
    return mat;
}

void freeMatrix(Mat *mat) {
    int i;
    for(i=0; i< mat->row; i++)
        free(mat->data[i]);
    free(mat->data);
    free(mat);
}

// porównuje Macierzy. Żeby nie tworzyć takich samych plików
int compare (Mat *mat1, Mat *mat2) {
    int sumTheSame = 0;
    int numberOfAllCells = mat1 -> col * mat1 -> row;
    
    for (int i = 0; i < mat1 -> row; i++)
            for (int j = 0; j < mat1 -> col; j++)
                if (mat2 -> data[i][j] == mat1 -> data[i][j])
                    sumTheSame++;
    
    if (sumTheSame == numberOfAllCells)
        return 1;
    
    return 0;
}

