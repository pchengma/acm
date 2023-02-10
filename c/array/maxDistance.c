// LeetCode: 1162. As Far from Land as Possible (Medium)
int maxDistance(int **grid, int gridSize, int *gridColSize) {
    int k = 2;
    int flag = 0;
    do {
        flag = 0;
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < *gridColSize; j++) {
                if (grid[i][j] == (k - 1)) {
                    if (i > 0 && grid[i - 1][j] == 0) {
                        grid[i - 1][j] = k;
                        flag = 1;
                    }
                    if (i < gridSize - 1 && grid[i + 1][j] == 0) {
                        grid[i + 1][j] = k;
                        flag = 1;
                    }
                    if (j > 0 && grid[i][j - 1] == 0) {
                        grid[i][j - 1] = k;
                        flag = 1;
                    }
                    if (j < *gridColSize - 1 && grid[i][j + 1] == 0) {
                        grid[i][j + 1] = k;
                        flag = 1;
                    }
                }
            }
        }
        if (flag) {
            k++;
        }
    } while (flag);
    return k == 2 ? -1 : k - 2;
}
