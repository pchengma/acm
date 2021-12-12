// LeetCode: 416. Partition Equal Subset Sum (Medium)
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;

        for (auto x: nums) {
            sum += x;
        }

        if (sum % 2) {
            return false;
        }

        sum >>= 1;

        vector<bool> dp(sum + 1, false);

        dp[0] = true;
        for (auto x: nums) {
            for (int i = sum; i >= x; --i) {
                dp[i] = dp[i] || dp[i - x];
            }
        }

        return dp[sum];
    }
};