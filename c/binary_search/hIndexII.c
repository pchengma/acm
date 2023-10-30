// LeetCode: 275. H-Index II (Medium)
int hIndex(int *citations, int citationsSize) {
    int left = 0, right = citationsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (citations[mid] >= citationsSize - mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return citationsSize - left;
}
