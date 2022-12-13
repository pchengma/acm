// LeetCode: 931. Minimum Falling Path Sum (Medium)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int dfs(int **matrix, int matrixSize, int row, int col, int memo[][101]) {
    if (row == matrixSize)
        return 0;

    if (memo[row][col] != INT_MAX)
        return memo[row][col];

    int min = INT_MAX;
    for (int i = -1; i <= 1; i++) {
        int colNext = col + i;
        if (colNext < 0 || colNext > matrixSize - 1)
            continue;
        min = MIN(min, dfs(matrix, matrixSize, row + 1, colNext, memo));
    }

    memo[row][col] = min + matrix[row][col];
    return memo[row][col];
}

int minFallingPathSum(int **matrix, int matrixSize, int *matrixColSize) {
    int min = INT_MAX;
    int memo[101][101] = {0};
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            memo[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        min = MIN(min, dfs(matrix, matrixSize, 0, i, memo));
    }
    return min;
}
