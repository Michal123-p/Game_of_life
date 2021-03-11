#ifndef _ACTUALIZE_H
#define _ACTUALIZE_H

#include "matrix-io.h"

int countAliveCells (Mat *mat, int x, int y, int type);
 
Mat* updateMatrix (Mat *mat, int type);

Mat* fixMatrix (Mat *mat);

int compare (Mat *mat1, Mat *mat2);

#endif
