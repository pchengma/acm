// LeetCode: 268. Missing Number (Easy)
int Cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int missingNumber(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), Cmp);
    int ans = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != i) {
            ans = i;
            break;
        }
    }
    if (i == numsSize) {
        ans = numsSize;
    }
    return ans;
}