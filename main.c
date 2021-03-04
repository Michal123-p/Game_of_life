#include <stdio.h>
#include <stdlib.h>
#include "matrix-io.h"
#include "actualize.h"


void writeMatrix (FILE* out, Mat *mat);

int main(int argc, char **argv) {
	
    /*
	if(argc < 2) {
		printf("Błędna liczba podawanych argumentów");
		return 1;
	}*/
    Mat *mat = readFromFile(argv[1]);

    FILE *out = argc > 2 ? fopen(argv[2], "w") : stdout;
    if (out == NULL) {
            fprintf(stderr, "%s: nie moge pisac do %s\n", argv[0], argv[2]);
            return 2;
    }
    printf("Hello");
    mat = updateMatrix (mat);
    writeMatrix (out, mat);
    
    fclose(out);
	return 0;

}

void writeMatrix (FILE* out, Mat *mat) {
    fprintf(out, "Hello");
    for (int i = 0; i < mat->row; i++) {
        for (int j = 0; j < mat->col; j++)
            fprintf(out, "%d ", mat->data[i][j]);
        fprintf(out, "/n");
    }
    printf("Hello");
    for (int i = 0; i < mat->row; i++) {
        for (int j = 0; j < mat->col; j++)
            printf("%d ", mat->data[i][j]);
        printf("/n");
    }
}
    
