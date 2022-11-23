// LeetCode: 41. First Missing Positive (Hard)
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int firstMissingPositive(int *nums, int numsSize) {
    int i;
    while (i < numsSize) {
        if (nums[i] >= 1 && nums[i] <= numsSize) {
            if (i + 1 != nums[i] && nums[i] != nums[nums[i] - 1]) {
                swap(&nums[i], &nums[nums[i] - 1]);
                continue;
            }
        }
        i++;
    }
    for (i = 0; i < numsSize; i++) {
        if (i + 1 != nums[i]) {
            return i + 1;
        }
    }
    return numsSize + 1;
}