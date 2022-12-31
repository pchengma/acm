// LeetCode: 980. Unique Paths III (Hard)
int pathnum;
int zeronum;

void dfs(int **grid, int gridSize, int *gridColSize, int t, int x, int y) {
    if (x < 0 || x >= gridSize || y < 0 || y >= gridColSize[0]) {
        return;
    }
    if (grid[x][y] == 2 && t != zeronum) {
        return;
    }
    if (grid[x][y] == 2 && t == zeronum) {
        pathnum++;
        return;
    }
    if (grid[x][y] == -1) {
        return;
    }
    int temp = grid[x][y];
    grid[x][y] = -1;
    dfs(grid, gridSize, gridColSize, t + 1, x - 1, y);
    dfs(grid, gridSize, gridColSize, t + 1, x + 1, y);
    dfs(grid, gridSize, gridColSize, t + 1, x, y + 1);
    dfs(grid, gridSize, gridColSize, t + 1, x, y - 1);
    grid[x][y] = temp;
}

int uniquePathsIII(int **grid, int gridSize, int *gridColSize) {
    pathnum = 0;
    zeronum = 0;
    int x, y;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 0) {
                zeronum++;
            }
            if (grid[i][j] == 1) {
                x = i;
                y = j;
            }
        }
    }
    dfs(grid, gridSize, gridColSize, -1, x, y);
    return pathnum;
}
