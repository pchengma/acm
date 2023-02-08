// LeetCode: 45. Jump Game II (Medium)
int jump(int *nums, int numsSize) {
    int *dp = (int *) malloc(sizeof(int) * numsSize);
    dp[0] = 0;
    int i, j;
    for (i = 1; i < numsSize; i++) {
        dp[i] = numsSize + 1;
    }

    for (i = 1; i < numsSize; i++) {
        for (j = 0; j < i; j++) {
            if (j + nums[j] >= i) {
                dp[i] = fmin(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[numsSize - 1];
}
