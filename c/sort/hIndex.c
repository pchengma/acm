// LeetCode: 274. H-Index (Medium)
int Cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int hIndex(int *citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), Cmp);
    if (citations[0] >= citationsSize) {
        return citationsSize;
    }

    int ans = citationsSize;
    int i;
    for (i = 0; i < citationsSize; i++) {
        if (citations[i] > citationsSize - i - 1) {
            break;
        }
    }
    ans = citationsSize - i;
    return ans;
}