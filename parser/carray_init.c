#include "cdef_north.h"

// get a particular element from an array initializer
node_t *c_array_get_init(symbol_t *sp, int *dim_values, int *dim_idx, node_t *ip)
{
    int i, j;

    if (ip->op != ARRAY) return NULL;

    // position after the topmost ARRAY node
    ip = ip->left.np;
    for (i=0; i<sp->dims; i++) {
        for (j=0; j<dim_values[i]-dim_idx[i]-1; j++) {
            if (ip->left.np == NULL)
                fatal("Internal error CA%d: Unexpected end of array expression", __LINE__);
            ip = ip->left.np;
        }
        // if we hit a comma, go right
        if (ip->op == ',')
            ip = ip->right.np;
        //if we are at an array go left
        if (ip->op == ARRAY)
            ip = ip->left.np;
        // check again for a leaf
        if (ip->leaf)
            break;
    }
    if (!ip->leaf)
        fatal("Internal error CA%d: Failed to locate entry in array initialization expression", __LINE__);

    return ip;
}
