#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#include "matrix-io.h"
#include "actualize.h"


#define N 25;
#define MAX_DIR 10000;
#define Sasiedztwo 1;

// Sasiedztwo = 1 to sasiedztwo Morea, Sasiedztwo = 0 to sasiedztwo von Neumana

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
    int sasiedztwo = argc > 3 ? atoi(argv[3]) : Sasiedztwo;
    if (sasiedztwo != 1 && sasiedztwo !=0 ) {
	printf("Sasiedztwo powinno wynosić 1 lub 0 a wynosi: %d \n", sasiedztwo);
	return -1;}
    char buf[20];
    char mkd[20];
    char bufor[40];
    
    for(i = 0; i < max; i++) {
        snprintf(mkd, 20, "folder%d", i);
        dir = mkdir(mkd, 0777);
        if (dir == 0)
            break;
	}
    
    Mat *matNew = createMatrix(mat -> row,  mat -> col);
    int resultOfComparison = 0;
    //matNew = updateMatrix (mat);
    
    for(i = 0; i < n; i++) {
        snprintf(buf, 20, "/file%d.pbm", i);
        strcpy(bufor,mkd);
        strcat(bufor,buf);
        
        matNew = updateMatrix (mat, sasiedztwo);
        resultOfComparison = compare (mat, matNew);
        
        if (resultOfComparison == 1) {
            //printf("Niepowtarzających się znaczeń: %d \n", i);
            break;
        }
        else
            mat = matNew;
        
        FILE *out = fopen(bufor, "w");
        saveImage(out, mat);
        fclose(out);
        bufor[0] = '\0';
    }
    
	// Dodanie jednego pliku w foramcie wyjściwoym
    snprintf(buf, 20, "/file%d.txt", i);
    strcpy(bufor, mkd);
    strcat(bufor, buf);
    FILE *out = fopen(bufor, "w");
    writeMatrix (out, mat);
    
    fclose(out);
	freeMatrix(mat);
    
	return 0;
	
}



