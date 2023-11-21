// LeetCode: 2216. Minimum Deletions to Make Array Beautiful (Medium)
int minDeletion(int *nums, int numsSize) {
    int ans = 0;
    bool check = true;
    for (int i = 0; i + 1 < numsSize; i++) {
        if (nums[i] == nums[i + 1] && check) {
            ans++;
        } else {
            check = !check;
        }
    }
    if ((numsSize - ans) % 2 != 0) {
        ans++;
    }
    return ans;
}
