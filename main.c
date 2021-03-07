#include <stdio.h>
#include <stdlib.h>
#include "matrix-io.h"
#include "actualize.h"
#include <sys/stat.h>
#include <string.h>

#define N 25;
#define MAX_DIR 10000;

int main(int argc, char **argv) {
    
    Mat *mat = readFromFile(argv[1]);
    if (mat == NULL) {
        fprintf(stderr, "Nie moge wczytac macierzy %s:\t", argv[1]);
        return 2;
    }
    int i;
    int dir = -1;
    int max = MAX_DIR;
    int n = argc > 2 ? atoi(argv[2]) : N;
    
    char buf[20];
    char mkd[20];
    char bufor[40];
    for(i=0; i<max; i++) {
	snprintf(mkd,20,"folder%d",i);
	dir = mkdir(mkd,0777);
	if (dir == 0)
	    break;

	}

    for(i = 0; i < n; i++) {
        snprintf(buf, 20, "/file%d.txt", i);
	strcpy(bufor,mkd);
	strcat(bufor,buf);
	printf(bufor);
	printf("\n");
        FILE *out = fopen(bufor, "w");
        mat = updateMatrix (mat);
    	fprintf(out,"P1\n#\n%d %d\n", mat->col,mat->row);
        writeMatrix (out, mat);
        fclose(out);
	bufor[0] = '\0';
    }
	// Dodanie jednego pliku w foramcie wyjściwoym
        snprintf(buf, 20, "/file%d.txt", i);	
	
	strcpy(bufor,mkd);
	strcat(bufor,buf);

        printf("%s", bufor);
        FILE *out = fopen(bufor, "w");
    	fprintf(out,"%d %d\n", mat->col,mat->row);
        writeMatrix (out, mat);
        fclose(out); 
	return 0;
	
}

    
/*
 * funkcja compare - porównuje obecny stan i nowy
 * plik actualize.c - compare
 * matrix-io.c - writeMatrix
 * main.c - generacja plików graficznych
 */
