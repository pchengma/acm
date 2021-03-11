#include "gf_mat.h"

unsigned char gf_add_built_in_xor(unsigned char a, unsigned char b) {
    return a ^ b;
}

unsigned char gf_mul_naive(unsigned char a, unsigned char b) {
    unsigned char res = 0u;
    while (b) {
        if (b & 1u) {
            res ^= a;
        }
        if (a & 0x80u) {  // if a >= 128, then it will overflow when shifted left, so reduce
            a = a << 1u;
            a = a ^ 29u;  // 0b11101
        } else {
            a <<= 1u;
        }
        b >>= 1u;
    }
    return res;
}

/*
 * a = 255, b <= 255
 * return inv of b
 * There must be a pair of int x and y.
 */
int gf_inv_by_built_in(unsigned int a, unsigned int b, unsigned int *x, unsigned int *y) {
    // Base Case
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    unsigned int x1, y1; // To store results of recursive call
    int gcd = gf_inv_by_built_in(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int try_gf_inv2(int a, int b) {
    int x, y;
    unsigned int x1 = 0, y1 = 1;  // To store results of recursive call
    // Base Case
    while (a != 0) {
        x = y1 - (b / a) * x1;
        y = x1;

        x1 = x;
        y1 = y;
        int temp = a;
        a = b % a;
        b = temp;
    }

    return y;
}

/*
 * dim_row: n
 * dim_col: n
 * (1/det(A))adj(A) = inverse of A
 */
int gf_invert_matrix_by_built_in_xor(unsigned char *in_mat, unsigned char *out_mat, const int n) {
    int i, j, k, x, y, ret;
    unsigned char temp;

    // Set out_mat[] to the identity matrix
    for (i = 0; i < n * n; ++i)    // memset(out_mat, 0, n*n)
        out_mat[i] = 0;

    for (i = 0; i < n; ++i)
        out_mat[i * n + i] = 1;

    // Inverse
    for (i = 0; i < n; ++i) {
        // Check for 0 in pivot element: Check existence:
        if (in_mat[i * n + i] == 0) {
            // Find a row with non-zero in current column and swap
            for (j = i + 1; j < n; ++j)
                if (in_mat[j * n + i])
                    break;

            if (j == n)    // Couldn't find means it's singular
                return -1;

            for (k = 0; k < n; ++k) {    // Swap rows i,j
                temp = in_mat[i * n + k];
                in_mat[i * n + k] = in_mat[j * n + k];
                in_mat[j * n + k] = temp;

                temp = out_mat[i * n + k];
                out_mat[i * n + k] = out_mat[j * n + k];
                out_mat[j * n + k] = temp;
            }
        }

        // Calculate inverse:
        // scale corresponding row
        temp = try_gf_inv2(255, in_mat[i * n + i]);  // 1/pivot
        for (j = 0; j < n; j++) {    // Scale row i by 1/pivot
            in_mat[i * n + j] = gf_mul_by_built_in_xor(in_mat[i * n + j], temp);
            out_mat[i * n + j] = gf_mul_by_built_in_xor(out_mat[i * n + j], temp);
        }
        // mul minor
        for (j = 0; j < n; ++j) {
            if (j == i)
                continue;

            temp = in_mat[j * n + i];
            for (k = 0; k < n; ++k) {
                out_mat[j * n + k] ^= gf_mul_by_built_in_xor(temp, out_mat[i * n + k]);
                in_mat[j * n + k] ^= gf_mul_by_built_in_xor(temp, in_mat[i * n + k]);
            }
        }
    }
    return 0;
}

/*
void init_ec_tables(int *mat, int length) {
    for (int i = 0; i < length; ++i) {
        int temp;
        if (i > 254) {
            temp = i % 255;
        } else {
            temp = i;
        }
    }
}

void gen_inreducible_poly() {

}
*/
