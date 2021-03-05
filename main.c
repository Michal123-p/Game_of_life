#include <stdio.h>
#include <stdlib.h>
#include "matrix-io.h"
#include "actualize.h"

#define N 25;

void writeMatrix (FILE* out, Mat *mat);

int main(int argc, char **argv) {
    
    Mat *mat = readFromFile(argv[1]);
    if (mat == NULL) {
        fprintf(stderr, "Nie moge wczytac macierzy %s:\t", argv[1]);
        return 2;
    }
    
    int n = argc > 2 ? atoi(argv[2]) : N;
    
    char buf[20];
    for(int i = 0; i < n; i++) {
        snprintf(buf, 20, "file%d", i);
        printf("%s", buf);
        FILE *out = fopen(buf, "w");
        mat = updateMatrix (mat);
    	fprintf(out,"P1\n#\n%d %d\n", mat->col,mat->row);
        writeMatrix (out, mat);
        fclose(out);
    }
	// Dodanie jednego pliku w foramcie wyjściwoym
        snprintf(buf, 20, "file%d", i);	
        printf("%s", buf);
        FILE *out = fopen(buf, "w");
        writeMatrix (out, mat);
        fclose(out);
	return 0;

}

void writeMatrix (FILE* out, Mat *mat) {
    for (int i = 0; i < mat->row; i++) {
        for (int j = 0; j < mat->col; j++)
            fprintf(out, "%d ", mat->data[i][j]);
        fprintf(out, "\n");
    }
    for (int i = 0; i < mat->row; i++) {
        for (int j = 0; j < mat->col; j++)
            printf("%d ", mat->data[i][j]);
        printf("\n");
    }
}
    
/*
 * funkcja compare - porównuje obecny stan i nowy
 * plik actualize.c - compare
 * matrix-io.c - writeMatrix
 * main.c - generacja plików graficznych
 */
