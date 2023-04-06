// LeetCode: 1254. Number of Closed Islands (Medium)
int g_format[][2] = {{-1, 0},
                     {1,  0},
                     {0,  -1},
                     {0,  1}};

void DFS(int **grid, int gridSize, int gridColSize, int *flag, int indexX, int indexY) {
    if (indexX < 0 || indexY < 0 || indexX >= gridSize || indexY >= gridColSize) {
        (*flag) = 1;
        return;
    }
    if (grid[indexX][indexY] == 1) {
        return;
    }
    grid[indexX][indexY] = 1;
    for (int i = 0; i < 4; i++) {
        DFS(grid, gridSize, gridColSize, flag, indexX + g_format[i][0], indexY + g_format[i][1]);
    }
    return;
}

int closedIsland(int **grid, int gridSize, int *gridColSize) {
    int retNum = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 0) {
                int flag = 0;
                DFS(grid, gridSize, gridColSize[0], &flag, i, j);
                if (flag == 0) {
                    retNum++;
                }
            }
        }
    }
    return retNum;
}
