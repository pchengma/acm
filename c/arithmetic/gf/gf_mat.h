#ifndef ACM_GF_MAT_H
#define ACM_GF_MAT_H

#include <stdio.h>

unsigned char gf_add_built_in_xor(unsigned char a, unsigned char b);

unsigned char gf_mul_by_built_in_xor(unsigned char a, unsigned char b);

int gf_inv_by_built_in(unsigned int a, unsigned int b, unsigned int *x, unsigned int *y);

int gf_invert_matrix_by_built_in_xor(unsigned char *in_mat, unsigned char *out_mat, const int n);

#endif //ACM_GF_MAT_H
