// LeetCode: Maximal Score After Applying K Operations (Medium)
void swap(int *nums, int i, int j) {
    int x = nums[i];
    nums[i] = nums[j];
    nums[j] = x;
}

void down(int *nums, int size, int i) {
    for (int k = 2 * i + 1; k < size; k = 2 * k + 1) {
        // 父节点 (k - 1) / 2，左子节点 k，右子节点 k + 1
        if (k + 1 < size && nums[k] < nums[k + 1]) {
            k++;
        }
        if (nums[k] < nums[(k - 1) / 2]) {
            break;
        }
        swap(nums, k, (k - 1) / 2);
    }
}

void Init(int *nums, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        down(nums, size, i);
    }
}

void Push(int *nums, int size, int x) {
    nums[size] = x;
    for (int i = size; i > 0 && nums[(i - 1) / 2] < nums[i]; i = (i - 1) / 2) {
        swap(nums, i, (i - 1) / 2);
    }
}

int Pop(int *nums, int size) {
    swap(nums, 0, size - 1);
    down(nums, size - 1, 0);
    return nums[size - 1];
}

long long maxKelements(int *nums, int numsSize, int k) {
    Init(nums, numsSize);
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        int x = Pop(nums, numsSize);
        ans += x;
        Push(nums, numsSize - 1, (x + 2) / 3);
    }
    return ans;
}
