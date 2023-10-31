// LeetCode: 2433. Find The Original Array of Prefix Xor (Medium)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findArray(int *pref, int prefSize, int *returnSize) {
    int *ans = (int *) malloc(sizeof(int) * prefSize);
    memset(ans, 0, sizeof(int));
    ans[0] = pref[0];
    for (int i = 1; i < prefSize; i++) {
        ans[i] = pref[i] ^ pref[i - 1];
    }
    *returnSize = prefSize;
    return ans;
}