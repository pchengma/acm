// LeetCode: 414. Third Maximum Number (Easy)
int GetMax(int *nums, int numsSize) {
    int max = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    return max;
}

int GetSecondMax(int *nums, int numsSize, int max) {
    int temp = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (temp < nums[i] && nums[i] != max) {
            temp = nums[i];
        }
    }
    return temp;
}

int GetThirdMax(int *nums, int numsSize, int max, int secondMax) {
    int temp = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (temp < nums[i] && nums[i] != max && nums[i] != secondMax) {
            temp = nums[i];
        }
    }
    return temp;
}

int Cmp(const void *a, const void *b) {
    if (*(int *) a < *(int *) b) {
        return -1;
    }
    return 1;
}

int Dedup(int *nums, int numsSize) {
    int size = 0;
    qsort(nums, numsSize, sizeof(int), Cmp);
    int *temp = (int *) malloc(sizeof(int) * numsSize);
    memset(temp, 0, sizeof(int) * numsSize);
    temp[size] = nums[0];
    size++;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != temp[size - 1]) {
            temp[size] = nums[i];
            size++;
        }
    }
    for (int i = 0; i < size; i++) {
        nums[i] = temp[i];
    }
    return size;
}

int thirdMax(int *nums, int numsSize) {
    int ans = 0;
    numsSize = Dedup(nums, numsSize);
    if (numsSize < 3) {
        ans = GetMax(nums, numsSize);
        return ans;
    }
    int max = GetMax(nums, numsSize);
    int secondMax = GetSecondMax(nums, numsSize, max);
    ans = GetThirdMax(nums, numsSize, max, secondMax);
    return ans;
}
