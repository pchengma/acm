// LeetCode: 2656. Maximum Sum With Exactly K Elements (Easy)
int GetMax(int *nums, int numsSize) {
    int max = 0;
    int idx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (max < nums[i]) {
            max = nums[i];
            idx = i;
        }
    }
    return idx;
}

int maximizeSum(int *nums, int numsSize, int k) {
    int ans = 0;
    int idx = GetMax(nums, numsSize);
    ans = nums[idx] * k + (k - 1) * k / 2;
    return ans;
}