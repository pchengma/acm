// LeetCode: 746. Min Cost Climbing Stairs (Easy)
class MinCostClimbingStairs {
public:
    int utility(vector<int> &cost, int index, vector<int> &dp) {
        if (index >= cost.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int ostep = cost[index] + utility(cost, index + 1, dp);
        int tstep = cost[index] + utility(cost, index + 2, dp);

        return dp[index] = min(ostep, tstep);
    }

    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> dp(cost.size(), -1);

        return min(utility(cost, 0, dp), utility(cost, 1, dp));
    }
};