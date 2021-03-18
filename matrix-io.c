#include <stdlib.h>

#include "matrix-io.h"

//wczytanie macierzy
//zapisanie macierzy do pliku

Mat* readFromFile( char *filename) {

	// row to wiersze, col to kolumny, rowi, coli to iteratory po kolumnach i wierszach

	int row = 0, col = 0;
	int rowi, coli;
	FILE *in = fopen(filename, "r");
	Mat *mat = NULL;
	
	if (in != NULL) {
		fscanf(in,"%d %d", &row, &col);
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

// dla wypisania w formacie .pbm
void saveImage(FILE* out, Mat *mat) {
    fprintf(out,"P1\n#\n%d %d\n", mat->col,mat->row);
    for (int i = 0; i < mat->row; i++) {
        for (int j = 0; j < mat->col; j++)
            fprintf(out, "%d ", mat->data[i][j]);
        fprintf(out, "\n");
    }
}

// dla wypisania w formacie .txt
void writeMatrix(FILE *out, Mat *mat) {
  fprintf(out,"%d %d\n", mat->col,mat->row); 
  for (int i = 0; i < mat->row; i++) {
        for (int j = 0; j < mat->col; j++)
            fprintf(out, "%d ", mat->data[i][j]);
        fprintf(out, "\n");
    }
}

