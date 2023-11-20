// LeetCode: 53. Maximum Subarray (Medium)
int maxSubArray(int *nums, int numsSize) {
    int pos = 0;
    for (pos = 0; pos < numsSize; pos++) {
        if (nums[pos] >= 0) {
            break;
        }
    }
    int max = nums[0];
    if (pos == numsSize) {
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        return max;
    }
    int sum = 0;
    max = 0;
    for (int i = pos; i < numsSize; i++) {
        if (sum + nums[i] < 0) {
            sum = 0;
        } else {
            sum += nums[i];
            if (sum > max) {
                max = sum;
            }
        }
    }
    return max;
}