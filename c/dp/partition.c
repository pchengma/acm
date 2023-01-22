// LeetCode: 131. Palindrome Partitioning (Medium)
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(char *s, int n, int i, int **f, char ***ret, int *retSize, int *retColSize, char **ans, int *ansSize) {
    if (i == n) {
        char **tmp = malloc(sizeof(char *) * (*ansSize));
        for (int j = 0; j < (*ansSize); j++) {
            int ansColSize = strlen(ans[j]);
            tmp[j] = malloc(sizeof(char) * (ansColSize + 1));
            strcpy(tmp[j], ans[j]);
        }
        ret[*retSize] = tmp;
        retColSize[(*retSize)++] = *ansSize;
        return;
    }
    for (int j = i; j < n; ++j) {
        if (f[i][j]) {
            char *sub = malloc(sizeof(char) * (j - i + 2));
            for (int k = i; k <= j; k++) {
                sub[k - i] = s[k];
            }
            sub[j - i + 1] = '\0';
            ans[(*ansSize)++] = sub;
            dfs(s, n, j + 1, f, ret, retSize, retColSize, ans, ansSize);
            --(*ansSize);
        }
    }
}

char ***partition(char *s, int *returnSize, int **returnColumnSizes) {
    int n = strlen(s);
    int retMaxLen = n * (1 << n);
    char ***ret = malloc(sizeof(char **) * retMaxLen);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * retMaxLen);
    int *f[n];
    for (int i = 0; i < n; i++) {
        f[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            f[i][j] = 1;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
        }
    }
    char *ans[n];
    int ansSize = 0;
    dfs(s, n, 0, f, ret, returnSize, *returnColumnSizes, ans, &ansSize);
    return ret;
}
