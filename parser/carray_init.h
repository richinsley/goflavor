#ifndef CARRAY_INIT_H
#define CARRAY_INIT_H

#include "symbol.h"

// get a particular element from an array initializer
node_t *c_array_get_init(symbol_t *sp, int *dim_values, int *dim_idx, node_t *ip);

#endif // CARRAY_INIT_H
