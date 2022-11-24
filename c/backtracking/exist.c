// LeetCode: 79. Word Search (Medium)
int m, n;

bool isValid(int i, int j) {
    if (i >= 0 && j >= 0 && i < m && j < n)
        return true;
    return false;
}

bool hasPath(char **board, char *word, int i, int j, int len, bool *vis) {
    if (word[len] == '\0') return true;
    bool isPath = false;

    if (!isValid(i, j))
        return false;
    if (!vis[i * n + j] && word[len] == board[i][j]) {
        vis[i * n + j] = true;
        isPath = hasPath(board, word, i, j + 1, len + 1, vis)
                 || hasPath(board, word, i, j - 1, len + 1, vis)
                 || hasPath(board, word, i + 1, j, len + 1, vis)
                 || hasPath(board, word, i - 1, j, len + 1, vis);

        if (!isPath) {
            vis[i * n + j] = false;
        }
    }
    return isPath;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word) {
    m = boardSize;
    n = *boardColSize;
    if (board == NULL || m < 1 || n < 1 || word == NULL)
        return false;
    bool *vis;
    vis = (bool *) malloc(sizeof(bool) * m * n);
    memset(vis, 0, m * n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            if (hasPath(board, word, i, j, 0, vis))
                return true;
    }
    return false;
}