// LeetCode: 307. Range Sum Query - Mutable (Medium)
typedef struct {
    int *nums;
    int *tree;
    int treeSize;
} NumArray;

int lowBit(int x) {
    return x & -x;
}

void add(int *tree, int treeSize, int index, int val) {
    while (index < treeSize) {
        tree[index] += val;
        index += lowBit(index);
    }
}

int prefixSum(const int *tree, int index) {
    int sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= lowBit(index);
    }
    return sum;
}

NumArray *numArrayCreate(int *nums, int numsSize) {
    NumArray *obj = (NumArray *) malloc(sizeof(NumArray));
    obj->nums = (int *) malloc(sizeof(int) * numsSize);
    memcpy(obj->nums, nums, sizeof(int) * numsSize);
    obj->treeSize = numsSize + 1;
    obj->tree = (int *) malloc(sizeof(int) * obj->treeSize);
    memset(obj->tree, 0, sizeof(int) * obj->treeSize);
    for (int i = 0; i < numsSize; i++) {
        add(obj->tree, obj->treeSize, i + 1, nums[i]);
    }
    return obj;
}

void numArrayUpdate(NumArray *obj, int index, int val) {
    add(obj->tree, obj->treeSize, index + 1, val - obj->nums[index]);
    obj->nums[index] = val;
}

int numArraySumRange(const NumArray *obj, int left, int right) {
    return prefixSum(obj->tree, right + 1) - prefixSum(obj->tree, left);
}

void numArrayFree(NumArray *obj) {
    free(obj->nums);
    free(obj->tree);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);
 
 * int param_2 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/