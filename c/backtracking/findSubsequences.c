// LeetCode: 491. Non-decreasing Subsequences (Medium)
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **ans;
int ansSize;
int *temp;
int tempSize;

void dfs(int cur, int last, int *nums, int numsSize, int **returnColumnSizes) {
    if (cur == numsSize) {
        if (tempSize >= 2) {
            ans[ansSize] = malloc(sizeof(int) * tempSize);
            memcpy(ans[ansSize], temp, sizeof(int) * tempSize);
            (*returnColumnSizes)[ansSize++] = tempSize;
        }
        return;
    }
    if (nums[cur] >= last) {
        temp[tempSize++] = nums[cur];
        dfs(cur + 1, nums[cur], nums, numsSize, returnColumnSizes);
        tempSize--;
    }
    if (nums[cur] != last) {
        dfs(cur + 1, last, nums, numsSize, returnColumnSizes);
    }
}

int **findSubsequences(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    ans = malloc(sizeof(int *) * 32768);
    *returnColumnSizes = malloc(sizeof(int *) * 32768);
    temp = malloc(sizeof(int) * numsSize);
    ansSize = tempSize = 0;
    dfs(0, INT_MIN, nums, numsSize, returnColumnSizes);
    *returnSize = ansSize;
    return ans;
}
