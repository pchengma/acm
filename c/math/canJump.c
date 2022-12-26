// LeetCode: 55. Jump Game (Medium)
bool canJump(int *nums, int numsSize) {
    int i = numsSize - 2, nextPos = numsSize - 1;
    while (i >= 0) {
        if (nums[i] + i >= nextPos) {
            nextPos = i;
        }
        i--;
    }
    return (nextPos == 0) ? true : false;
}