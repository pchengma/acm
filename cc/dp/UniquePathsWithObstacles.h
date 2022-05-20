// LeetCode: 63. Unique Paths II (Medium)
class UniquePathsWithObstacles {
public:
    int uniquePathsWithObstacles(vector <vector<int>> &grid) {
        vector <vector<long long int>> dp(grid.size(), vector<long long int>(grid[0].size(), 0));

        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    if (i == grid.size() - 1 && j == grid[0].size() - 1) {
                        dp[i][j] = 1;
                    } else if (i == grid.size() - 1) {
                        dp[i][j] = dp[i][j + 1];
                    } else if (j == grid[0].size() - 1) {
                        dp[i][j] = dp[i + 1][j];
                    } else {
                        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                    }
                }
            }
        }

        return dp[0][0];
    }
};