// LeetCode: 474. Ones and Zeroes (Medium)
class FindMaxForm {
public:
    int findMaxForm(vector <string> &strs, int m, int n) {
        vector <vector<int>> dp(m + 1, vector<int>(n + 1));

        for (auto &s: strs) {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;

            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        return dp[m][n];
    }
};