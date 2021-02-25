
typedef struct Matrix {
	int row,col;
	int **data;

} Matrix;

Matrix *readFromFile(char *filename);

Matrix* createMatrix(int row, int col);

void freeMatrix(Matrix *mat);

void saveImage(Matrix *mat);
