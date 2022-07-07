// LeetCode: 97. Interleaving String (Medium)
class IsInterleave {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l = s1.size(), m = s2.size(), n = s3.size();
        if (l + m != n) return false;

        bool dp[101][101];
        memset(dp, 0, sizeof dp);

        for (int i = l; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                if (i == l and j == m) {
                    dp[i][j] = true;
                } else {
                    int idx = i + j;
                    if (s1[i] == s3[idx]) {
                        dp[i][j] = dp[i][j] or dp[i + 1][j];
                    }
                    if (s2[j] == s3[idx]) {
                        dp[i][j] = dp[i][j] or dp[i][j + 1];
                    }
                }
            }
        }

        return dp[0][0];
    }
};