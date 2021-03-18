#ifndef _ACTUALIZE_H
#define _ACTUALIZE_H

#include <stdio.h>

#include "matrix-action.h"


int countAliveCells (Mat *mat, int x, int y, int type);
 
Mat* updateMatrix (Mat *mat, int type);

Mat* fixMatrix (Mat *mat);


#endif
