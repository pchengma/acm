// LeetCode: 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts (Medium)
static int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int calMax(const int *arr, int arrSize, int boardr) {
    int res = 0, pre = 0;
    for (int i = 0; i < arrSize; i++) {
        res = fmax(arr[i] - pre, res);
        pre = arr[i];
    }
    return fmax(res, boardr - pre);
}

int maxArea(int h, int w, int *horizontalCuts, int horizontalCutsSize, int *verticalCuts, int verticalCutsSize) {
    int mod = 1e9 + 7;
    qsort(horizontalCuts, horizontalCutsSize, sizeof(int), cmp);
    qsort(verticalCuts, verticalCutsSize, sizeof(int), cmp);
    return (long long) calMax(horizontalCuts, horizontalCutsSize, h) * \
                      calMax(verticalCuts, verticalCutsSize, w) % mod;
}
