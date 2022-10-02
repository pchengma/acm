// LeetCode: 1155. Number of Dice Rolls With Target Sum (Medium)
class NumRollsToTarget {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(target + 1, 0);
        for (int i = 1; i <= min(target, k); i++) {
            dp[i] = 1;
        }
        n--;
        while (n--) {
            for (int i = target; i >= 1; i--) {
                dp[i] = 0;
                for (int j = max(1, i - 1); j >= max(1, i - k); j--) {
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }
        }
        return dp[target];
    }
};