// LeetCode: 2389. Longest Subsequence With Limited Sum (Easy)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

int *answerQueries(int *nums, int numsSize, int *queries, int queriesSize, int *returnSize) {
    int i = 0, j = 0;

    int *ans = (int *) malloc(sizeof(int) * queriesSize);
    memset(ans, 0, sizeof(int) * queriesSize);

    int flag = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for (i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
    }

    for (i = 0; i < queriesSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (nums[j] <= queries[i]) {
                ans[i] = j + 1;
            }
        }
    }

    *returnSize = queriesSize;

    return ans;
}
