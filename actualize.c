#include "actualize.h"

/* stany:
 0 - martwa
 1 - żywa
 2 - rodzi się (przejściowy stan)
 3 - ginie (przejściowy stan)
*/

int countAliveCells (Mat *mat, int x, int y, int type) {  // x i y to współrzędne punktu
	int sumAlive = 0;
	if (type == 1) {
	for (int i = x - 1; i < x + 2; i++) // iteracja po wierszach w sąsiedstwie
		for (int j = y - 1; j < y + 2; j++) // iteracja po kolumnach w sąsiedstwie
			if ( (i >= 0 && i < mat->row) && (j >= 0 && j < mat->col) && (i!= x || j!= y) )
				if(mat->data[i][j] == 1 || mat->data[i][j] == 3 )   // króra  tym momencie jest żywa
					sumAlive++;
        }
	else	{     
	int i = x-1;
	int j = y;
	if ( (i >= 0 && i < mat->row) && (j >= 0 && j < mat->col))
                                if(mat->data[i][j] == 1 || mat->data[i][j] == 3 )   // króra  tym momencie jest żywa
                                        sumAlive++;

        i+=2;
        if ( (i >= 0 && i < mat->row) && (j >= 0 && j < mat->col))
                                if(mat->data[i][j] == 1 || mat->data[i][j] == 3 )   // króra  tym momencie jest żywa
                                        sumAlive++;

	i-=1;
        j+=1;
        if ( (i >= 0 && i < mat->row) && (j >= 0 && j < mat->col))
                                if(mat->data[i][j] == 1 || mat->data[i][j] == 3 )   // króra  tym momencie jest żywa
                                        sumAlive++;
        j +=2;
        if ( (i >= 0 && i < mat->row) && (j >= 0 && j < mat->col))
                                if(mat->data[i][j] == 1 || mat->data[i][j] == 3 )   // króra  tym momencie jest żywa
                                        sumAlive++;	
	}
	return sumAlive;
}

Mat* updateMatrix (Mat *mat, int type) {
    Mat *matTemp = createMatrix (mat -> row, mat -> col);
    //matTemp = mat;
    
    for (int i = 0; i < mat->row; i++)
        for (int j = 0; j < mat->col; j++)
            matTemp -> data[i][j] = mat -> data[i][j];
    
    int sumAlive = 0;
    for (int i = 0; i < matTemp -> row; i++)
        for (int j = 0; j < matTemp -> col; j++) {
            sumAlive = countAliveCells(matTemp, i, j, type);
            if (matTemp -> data[i][j] == 1 && (sumAlive != 2 && sumAlive != 3))
                matTemp -> data[i][j] = 3;  //ginie
	   
            if (matTemp -> data[i][j] == 0 && sumAlive == 3)
                matTemp -> data[i][j] = 2;   //rodzi się
            }
    matTemp = fixMatrix(matTemp);
    return matTemp;
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
