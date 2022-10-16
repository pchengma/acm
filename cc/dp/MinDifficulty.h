// LeetCode: 1335. Minimum Difficulty of a Job Schedule (Hard)
class MinDifficulty {
public:
    int minDifficulty(vector<int> &jobDifficulty, int d) {
        int n = jobDifficulty.size(), inf = 1e9, maxd;
        if (n < d) return -1;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int k = 1; k <= d; ++k) {
            for (int i = 0; i <= n - k; ++i) {
                maxd = 0, dp[i] = inf;
                for (int j = i; j <= n - k; ++j) {
                    maxd = max(maxd, jobDifficulty[j]);
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};