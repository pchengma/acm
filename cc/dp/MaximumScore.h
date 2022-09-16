// LeetCode: 1770. Maximum Score from Performing Multiplication Operations (Medium)
class Solution {
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        vector <vector<int>> dp(multipliers.size() + 1, vector<int>(multipliers.size() + 1, 0));
        for (int i = multipliers.size() - 1; i >= 0; i--) {
            for (int j = multipliers.size() - i - 1; j >= 0; j--) {
                int s = nums[i] * multipliers[i + j] + dp[i + 1][j];
                int e = nums[nums.size() - j - 1] * multipliers[i + j] + dp[i][j + 1];
                dp[i][j] = max(s, e);
            }
        }
        return dp[0][0];
    }
};