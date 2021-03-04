#include <stdio.h>
#include "actualize.h"

/* stany:
 0 - martwa
 1 - żywa
 2 - rodzi się (przejściowy stan)
 3 - ginie (przejściowy stan)
*/

int countAliveCells (Mat *mat, int x, int y ) {  //x i y to współrzędne punktu
	int sumAlive = 0;
	for (int i = x - 1; i < x + 2; i++) // iteracja po wierszach w sąsiedstwie
		for (int j = y - 1; j < y + 2; j++) // iteracja po kolumnach w sąsiedstwie
			if ( (i >= 0 && i < mat->row) && (j >= 0 && j < mat->col) && (i!= x && j!= y) )
				if(mat->data[i][j] == 1 || mat->data[i][j] == 3 )   //króra w tym momencie jest żywa
					sumAlive++;
	return sumAlive;
}

Mat* updateMatrix (Mat *mat) {
    int sumAlive = 0;
    for (int i = 0; i < mat->row; i++)
        for (int j = 0; j < mat->col; j++) {
            sumAlive = countAliveCells(mat, i, j);
            if (mat->data[i][j] == 1 && (sumAlive != 2 && sumAlive != 3))
                mat->data[i][j] = 3;  //ginie
            if (mat->data[i][j] == 0 && sumAlive == 3)
                mat->data[i][j] = 2;   //rodzi się
            }
    mat = fixMatrix(mat);
    return mat;
}
    
Mat* fixMatrix (Mat *mat) {
    for (int i = 0; i < mat->row; i++)
        for (int j = 0; j < mat->col; j++) {
            if (mat->data[i][j] == 2)
                mat->data[i][j] = 1;
            if (mat->data[i][j] == 3)
                mat->data[i][j] = 0;
        }
    return mat;
}
 

