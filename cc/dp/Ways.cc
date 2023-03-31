// LeetCode: 1444. Number of Ways of Cutting a Pizza (Hard)
class Ways {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].length();
        long long modu = 1000000007LL;
        vector<vector<int>> sub(m+1, vector<int>(n+1));
        for(int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                sub[i][j] = sub[i+1][j] + sub[i][j+1] - sub[i+1][j+1] + (pizza[i][j] == 'A' ? 1 : 0);
            }
        }
        vector<vector<vector<long long>>> dp(k, vector<vector<long long>>(m,vector<long long>(n)));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[0][i][j] = sub[i][j] > 0 ? 1LL : 0LL;
            }
        }
        for (int o = 1; o < k; ++o) {
            for (int j = n-2; j >= 0; --j) {
                for (int h = 1; h + j < n; ++h)
                    dp[o][m-1][j] += sub[m-1][j] - sub[m-1][j+h] > 0 ? dp[o-1][m-1][j+h] : 0LL;
            }
        }
        for (int o = 1; o < k; ++o) {
            for (int j = m-2; j >= 0; --j) {
                for (int h = 1; h + j < m; ++h)
                    dp[o][j][n-1] += sub[j][n-1] - sub[j+h][n-1] > 0 ? dp[o-1][j+h][n-1] : 0LL;
            }
        }
        for (int o = 1; o < k; ++o) {
            for (int i = m - 2; i >= 0; --i) {
                for (int j = n - 2; j >= 0; --j) {
                    for (int h = 1; h < m - i; ++h) {
                        dp[o][i][j] += sub[i][j] - sub[i+h][j] > 0 ? dp[o-1][i+h][j] : 0LL;
                    }
                    for (int h = 1; h < n - j; ++h) {
                        dp[o][i][j] += sub[i][j] - sub[i][j+h] > 0 ? dp[o-1][i][j+h] : 0LL;
                    }
                }
            }
        }
        return (int)(dp[k-1][0][0] % modu);
    }
};
