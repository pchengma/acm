// LeetCode: 6. Zigzag Conversion (Medium)
char *convert(char *s, int numRows) {
    int n = strlen(s), r = numRows;
    if (r == 1 || r >= n) {
        return s;
    }
    int t = r * 2 - 2;
    int c = (n + t - 1) / t * (r - 1);
    char **mat = (char **) malloc(sizeof(char *) * r);
    for (int i = 0; i < r; i++) {
        mat[i] = (char *) malloc(sizeof(char) * c);
        memset(mat[i], 0, sizeof(char) * c);
    }
    for (int i = 0, x = 0, y = 0; i < n; ++i) {
        mat[x][y] = s[i];
        if (i % t < r - 1) {
            ++x;
        } else {
            --x;
            ++y;
        }
    }
    int pos = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j]) {
                s[pos++] = mat[i][j];
            }
        }
        free(mat[i]);
    }
    free(mat);
    return s;
}
