// LeetCode: 1143. Longest Common Subsequence (Medium)
int longestCommonSubsequence(char *text1, char *text2) {
    int m = strlen(text1), n = strlen(text2);
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        char c1 = text1[i - 1];
        for (int j = 1; j <= n; j++) {
            char c2 = text2[j - 1];
            if (c1 == c2) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

