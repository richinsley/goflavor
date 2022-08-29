#include "cdef_north.h"

// duplicate declaration for c_array_unroll_rec
static list_t *c_array_unroll_decl(list_t *lp, int *dim_values, int *dim_cnt, int *dim_skip)
{
    node_t *ip, **dim;
    list_t *ret;
    int i, j;

    // first, create the index expression
    dim = (node_t **)getmem((lp->dims+1)*sizeof(node_t *));
    for (i=0; i<lp->dims; i++)
        dim[i] = node(DBL_BRACE_L, leafi(INT_LITERAL, dim_cnt[i]), NULL);
    dim[i] = NULL;

    // find the init expression
    if (lp->sp->modifiers & M_CONST)
        ip = lp->sp->init;
    else
        ip = lp->e1;

    // position after the topmost ARRAY node
    ip = ip->left.np;
    for (i=0; i<lp->dims; i++) {
        if (dim_skip[i]) continue;
        for (j=0; j<dim_values[i]-dim_cnt[i]-1; j++) {
            if (ip->left.np == NULL)
                fatal("Internal error CA%d: Unexpected end of array expression", __LINE__);
            ip = ip->left.np;
        }
        // if we hit a comma, go right
        if (ip->op == ',')
            ip = ip->right.np;
        // if we are at an array go left
        if (ip->op == ARRAY)
            ip = ip->left.np;
        // check again for a leaf
        if (ip->leaf)
            break;
    }
    if (!ip->leaf)
        fatal("Internal error CA%d: Failed to locate entry in array initialization expression", __LINE__);

    // now create a duplicate list entry
    ret = ldup(lp);

    // attach
    ret->dim = dim;
    ret->e1 = ip;

    return ret;
}

// recursive helper for c_array_unroll
static list_t *c_array_unroll_rec(list_t *lp, int *dim_values, int *dim_cnt, int *dim_skip, int dim, list_t *prev)
{
    int i, begin, end;
    list_t *n, *ret;

    // if we reached the end, create duplicate
    if (dim == lp->dims) {
        n = c_array_unroll_decl(lp, dim_values, dim_cnt, dim_skip);
        if (prev == NULL)
            return n;
        else
            return app(prev, n);
    }
    if (dim_skip[dim]) {
        begin = dim_values[dim];
        end = begin+1;
    }
    else {
        begin = 0;
        end = dim_values[dim];
    }
    ret = prev;
    for (i=begin; i<end; i++) {
        dim_cnt[dim] = i;
        ret = c_array_unroll_rec(lp, dim_values, dim_cnt, dim_skip, dim+1, ret);
    }
    return ret;
}

// unrolls declaration of array initializers - this way no special code is needed in the code generator
list_t *c_array_unroll(list_t *lp)
{
    symbol_t *sp;
    node_t *ip, *p;
    int *dim_values, *dim_skip; // dim_skip is used to flag '[['
    int *dim_cnt;
    int i;
    list_t *ret = lp;

    sp = lp->sp;
    if (sp->modifiers & M_CONST)
        ip = sp->init;
    else
        ip = lp->e1;

    if (ip->op != ARRAY)
        fatal("Internal error CA%d: Cannot unroll array", __LINE__);

    // first, figure out the dimensions of the symbol
    dim_values = (int *)getmem(lp->dims*sizeof(int));
    dim_skip = (int *)getmem(lp->dims*sizeof(int));

    for (i=0; i<lp->dims; i++) {
        p = lp->dim[i];
        if (p == NULL)
            fatal("Internal error CA%d: Unexpected end of dimensioning array", __LINE__);

        // skip double braces
        if (p->op == DBL_BRACE_L)
            dim_skip[i]=1;
        else {
            dim_skip[i] = 0;
            if (p->op != '[')
                fatal("Internal error CA%d: Expected array expresion", __LINE__);
        }
        if (p->left.np == NULL)
            fatal("Internal error CA%d: Array expression without value", __LINE__);
        // invalid array size type has already been reported, as well as use of non-literals
        if (p->left.np->op != INT_LITERAL)
            goto c_array_unroll_end;
        dim_values[i] = p->left.np->left.ival;
    }

    // create our running counters array
    dim_cnt = (int *)getmem(lp->dims*sizeof(int));

    // finally, create list of declarations, one element at a time
    ret = c_array_unroll_rec(lp, dim_values, dim_cnt, dim_skip, 0, NULL);

c_array_unroll_end:
    free_memt(dim_values);
    free_memt(dim_skip);
    free_memt(dim_cnt);
    return ret;
}
