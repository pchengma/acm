// LeetCode: 944. Delete Columns to Make Sorted (Easy)
int minDeletionSize(char **strs, int strsSize) {
    int row = strsSize;
    int col = strlen(strs[0]);
    int ans = 0;
    for (int j = 0; j < col; ++j) {
        for (int i = 1; i < row; ++i) {
            if (strs[i - 1][j] > strs[i][j]) {
                ans++;
                break;
            }
        }
    }
    return ans;
}
