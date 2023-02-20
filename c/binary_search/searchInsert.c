// LeetCode: 35. Search Insert Position (Easy)
int searchInsert(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    if (nums[right] < target) {
        return right + 1;
    }
    if (nums[0] >= target) {
        return 0;
    }

    while (left <= right) {
        int middle = left + ((right - left) / 2);
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] < target) {
            left = middle + 1;
        } else if (nums[middle] > target) {
            right = middle - 1;
        }
    }
    return left;
}