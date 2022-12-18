// LeetCode: 739. Daily Temperatures (Medium)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize) {
    int *stack = (int *) malloc(temperaturesSize * sizeof(int)), sz = 0;
    int *ans = (int *) calloc(temperaturesSize, sizeof(int)), j = 0;
    *returnSize = temperaturesSize;
    for (int i = 0; i < temperaturesSize; i++) {
        int cur = temperatures[i];
        while (sz != 0 && cur > temperatures[stack[sz - 1]]) {
            int preIdx = stack[sz - 1];
            ans[preIdx] = i - preIdx;
            --sz;
        }
        stack[sz++] = i;
    }
    free(stack);
    return ans;
}
