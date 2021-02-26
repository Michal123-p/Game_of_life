#include <stdlib.h>
#include <stdio.h>
#include "matrix-io.h"

Matrix* readFromFile( char *filename) {

	// row to wiersze, col to kolumny, i to iteratory po kolumnach i wierszach
	// Oczekuje wartości int.
	int row, col;
	int rowi, coli;
	FILE *in = fopen(filename, "r");
	Matrix *mat = NULL;
	
	if (in != NULL) {
		fscanf(in,"%2d", &row, &col);
		mat = createMatrix(row,col);
		if (mat != NULL) {
		    for(rowi = 0; rowi < row; rowi++) {
                for(coli = 0; coli < col; coli++)
                    fscanf(in, "%d", &(mat -> data[rowi][coli]) );
                }
		} else {
			fprintf(stderr,"Błąd podczas tworzenia macierzy rozmiarów  %d x %d", row, col);
		} 

        fclose(in);
    }
	else {
		fprintf(stderr,"Błąd w otwarciu pliku: %s\n", filename);
	}
	return mat;
}

void freeMatrix(Matrix *mat) {
	int i;
	for(i=0; i< mat->row; i++)
		free(mat->data[i]);
	free(mat->data);
	free(mat);
}

Matrix* createMatrix(int r, int c) {
	int i;
	Matrix *mat = (Matrix*) malloc(sizeof(Matrix));
	if(mat != NULL) {
	    mat->row = r;
	    mat->col = c;
	    mat->data = (int**) malloc(sizeof(int*) * r);
	    for(i=0; i<r;i++) {
		mat->data[i] = (int*) malloc(sizeof(int) * c);
		}
	    }
	return mat;
}






