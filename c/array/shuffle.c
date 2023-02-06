// LeetCode: 1470. Shuffle the Array (Easy)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *shuffle(int *nums, int numsSize, int n, int *returnSize) {
    int i;
    int *ret = (int *) malloc(sizeof(int) * numsSize);

    for (i = 0; i < n; i++) {
        ret[i * 2] = nums[i];
        ret[i * 2 + 1] = nums[i + n];
    }

    *returnSize = numsSize;
    return ret;
}