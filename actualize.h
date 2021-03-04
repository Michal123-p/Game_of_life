#ifndef _ACTUALIZE_H
#define _ACTUALIZE_H

#include "matrix-io.h"

int countAliveCells (Mat *mat, int x, int y);
 
Mat* updateMatrix (Mat *mat);

Mat* fixMatrix (Mat *mat);

#endif
