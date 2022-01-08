// LeetCode: 1463. Cherry Pickup II (Hard)
class Solution {
public:
    int dp[75][75][75];
    int rl, cl;

    int hat(int c1, int c2, int r, vector <vector<int>> &grid) {
        if (r == rl) {
            return 0;
        }

        if (dp[c1][c2][r] != -1) {
            return dp[c1][c2][r];
        }

        int ans = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int C1 = c1 + i;
                int C2 = c2 + j;
                if (C1 >= 0 && C1 < cl && C2 >= 0 && C2 < cl) {
                    ans = max(ans, hat(C1, C2, r + 1, grid));
                }
            }
        }
        if (c1 == c2) {
            ans += grid[r][c1];
        } else if (c1 != c2) {
            ans += grid[r][c1] + grid[r][c2];
        }
        return dp[c1][c2][r] = ans;
    }

    int cherryPickup(vector <vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        rl = n;
        cl = m;
        memset(dp, -1, sizeof(dp));

        return hat(0, m - 1, 0, grid);


    }
};