#include "gf.c"

void lu(int len, int dim, uint8_t **src, uint8_t **l_mat, uint8_t **u_mat) {
    int i, j, l, k;

    uint8_t *x = (uint8_t *) malloc(sizeof(uint8_t) * len);
    uint8_t *y = (uint8_t *) malloc(sizeof(uint8_t) * len);
    memset(x, 0u, sizeof(uint8_t) * len);
    memset(y, 0u, sizeof(uint8_t) * len);

    // Get l_mat[i][0] by src[i][0]:
    for (i = 0; i < dim; ++i)
        for (l = 0; l < len; ++l)
            l_mat[i][l] = src[i][l];
    // Get u_mat[0][j] by src[0][j] / src[0][0]:
    for (j = 1; j < dim; ++j)
        for (l = 0; l < len; ++l)
            u_mat[0][j * len + l] = gf_mul_naive(src[0][j * len + l], gf_inv_naive(255u, l_mat[0][l], x, y));
    // Get u_mat[i][i] as 1:
    for (i = 0; i < dim; ++i)
        for (l = 0; l < len; ++l)
            u_mat[i][i * len + l] = 1u;
    // Get l_mat and u_mat:
    for (i = 1; i < dim; ++i) {
        for (j = 1; j < dim; ++j) {
            for (l = 0; l < len; ++l) {
                if (i >= j) {  // Get l_mat[i][j] by src[i][j] - l_mat[i][k] * u_mat[k][j]
                    l_mat[i][j * len + l] = src[i][j * len + l];
                    for (k = 0; k < j; ++k)
                        l_mat[i][j * len + l] ^= gf_mul_naive(l_mat[i][k * len + l], u_mat[k][j * len + l]);
                } else {  // Get u_mat[i][j] by (src[i][j] - l[i][k] * u_mat[k][j]) / l_mat[i][i]
                    u_mat[i][j * len + l] = src[i][j * len + l];
                    for (k = 0; k < j; ++k)
                        u_mat[i][j * len + l] ^= gf_mul_naive(l_mat[i][k * len + l], u_mat[k][j * len + l]);
                    u_mat[i][j * len + l] = gf_mul_naive(u_mat[i][j * len + l], gf_inv_naive(255u, l_mat[i][i * len + l], x, y));
                }
            }
        }
    }
}
