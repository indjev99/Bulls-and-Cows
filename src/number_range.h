#ifndef NUMBER_RANGE_H_INCLUDED
#define NUMBER_RANGE_H_INCLUDED

#include "params.h"
#include <math.h>

const int MIN_NUM = pow(BASE, NUM_DIGS - 1) + 0.5;
const int MAX_NUM = pow(BASE, NUM_DIGS) - 1 + 0.5;
const int POS_NUMS = MAX_NUM - MIN_NUM + 1;

#endif // NUMBER_RANGE_H_INCLUDED
