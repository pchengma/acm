// LeetCode: 198. House Robber (Medium)
int rob(int *nums, int numsSize) {
    int dp[numsSize];
    dp[0] = nums[0];
    if (numsSize == 1) {
        return nums[0];
    }
    int max = dp[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < numsSize; ++i) {
        dp[i] = nums[i] + dp[i - 2] < dp[i - 1] ? dp[i - 1] : nums[i] + dp[i - 2];
        max = dp[i] > max ? dp[i] : max;
    }
    return max > dp[1] ? max : dp[1];
}
