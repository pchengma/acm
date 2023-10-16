// LeetCode: 260. Single Number III (Medium)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *singleNumber(int *nums, int numsSize, int *returnSize) {
    int xorsum = 0;
    for (int i = 0; i < numsSize; i++) {
        xorsum ^= nums[i];
    }
    int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
    int type1 = 0, type2 = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num & lsb) {
            type1 ^= num;
        } else {
            type2 ^= num;
        }
    }

    int *ans = (int *) malloc(sizeof(int) * 2);
    ans[0] = type1;
    ans[1] = type2;
    *returnSize = 2;
    return ans;
}