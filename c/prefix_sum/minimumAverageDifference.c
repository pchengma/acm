// LeetCode: 2256. Minimum Average Difference (Medium)
int minimumAverageDifference(int *nums, int numsSize) {
    int i = 0;

    long long sum = 0;
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    int idx = 0;
    long long minAvgDiff = INT_MAX;
    long long prefixSum = 0;
    long long avgDiff = 0;

    for (i = 0; i < numsSize; i++) {
        prefixSum += nums[i];

        if (numsSize - i - 1 != 0) {
            avgDiff = abs((prefixSum / (i + 1))
                          - ((sum - prefixSum) / (numsSize - i - 1)));
        } else {
            avgDiff = abs(prefixSum / (i + 1));
        }

        if (minAvgDiff > avgDiff) {
            idx = i;
            minAvgDiff = avgDiff;
        }
    }

    return idx;
}
