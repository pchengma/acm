// LeetCode: 46. Permutations (Medium)
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtracking(int *nums, int numsSize, int **res, int *returnSize,
                  int **returnColumnSizes, int *path, int pathSize, int *used) {
    if (pathSize == numsSize) {
        res[*returnSize] = (int *) malloc(sizeof(int) * pathSize);
        memcpy(res[*returnSize], path, sizeof(int) * pathSize);
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i] == 1) {
            continue;
        }
        path[pathSize] = nums[i];
        used[i] = 1;
        backtracking(nums, numsSize, res, returnSize, returnColumnSizes, path, pathSize + 1, used);
        used[i] = 0;
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = (int *) malloc(sizeof(int) * 100001);
    int **res = (int **) malloc(sizeof(int *) * 100001);
    int *path = (int *) malloc(sizeof(int) * numsSize);
    int *used = (int *) malloc(sizeof(int) * numsSize);
    backtracking(nums, numsSize, res, returnSize, returnColumnSizes, path, 0, used);
    return res;
}