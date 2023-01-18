// LeetCode: 918. Maximum Sum Circular Subarray (Medium)
int maxSubarraySumCircular(int *nums, int numsSize) {
    int i = 1, sum = nums[0], min = nums[0], max = nums[0], singleMax = nums[0];
    int prevMin = (0 < nums[0]) ? 0 : nums[0];
    int prevMax = (0 > nums[0]) ? 0 : nums[0];

    while (numsSize > i) {
        sum += nums[i];

        if (singleMax < nums[i]) {
            singleMax = nums[i];
        }

        prevMax = (0 < prevMax) ? (prevMax + nums[i]) : nums[i];
        if (max < prevMax) {
            max = prevMax;
        }

        prevMin = (0 > prevMin) ? (prevMin + nums[i]) : nums[i];
        if (min > prevMin) {
            min = prevMin;
        }

        i++;
    }

    if (0 > singleMax) {
        return singleMax;
    }

    if (sum - min > max) {
        max = sum - min;
    }

    return max;
}
