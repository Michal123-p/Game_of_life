#include <stdio.h>
#include <stdlib.h>
#include "matrix-io.h"

int main(int argc, char **argv) {
	
	if(argc < 2) {
		printf("Błędna liczba podawanych argumentów");
		return 1;
	}
	Matrix *mat = readFromFile(argv[1]);
	
	
	return 0;

}
