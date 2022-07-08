// LeetCode: 1473. Paint House III (Hard)
class MinCost {
public:
    int m;
    int n;
    int dp[101][101][21];
    vector<int> houses;
    vector <vector<int>> cost;

    int solve(int i, int target, int prevColor) {
        if (i == m) {
            if (target == 0) {
                return 0;
            }
            return 1e8;
        }

        if (target == -1) {
            return 1e8;
        }

        if (i != -1 && target != -1 && prevColor != -1 && dp[i][target][prevColor] != -1) {
            return dp[i][target][prevColor];
        }

        if (houses[i] != -1) {
            return solve(i + 1, target - (houses[i] != prevColor), houses[i]);
        }

        int ans = 1e8;
        for (int color = 0; color < n; color++) {
            ans = min(ans, cost[i][color] + solve(i + 1, target - (color != prevColor), color));
        }

        if (i != -1 && target != -1 && prevColor != -1) {
            dp[i][target][prevColor] = ans;
        }
        return ans;
    }

    int minCost(vector<int> &houses, vector <vector<int>> &cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));

        for (int &x: houses) {
            x--;
        }

        this->m = m;
        this->n = n;
        this->houses = houses;
        this->cost = cost;
        int ans = solve(0, target, -1);
        return ans == 1e8 ? -1 : ans;
    }
};