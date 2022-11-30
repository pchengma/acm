// LeetCode: 1207. Unique Number of Occurrences (Easy)
bool uniqueOccurrences(int *arr, int arrSize) {
    int m[2002] = {0}, v[1001] = {0}, *a = m + 1000, i;
    for (i = 0; i < arrSize; a[arr[i++]]++);
    for (i = 0; i < 2001 && !v[m[i]]; v[m[i++]] = m[i]);
    return !v[m[i]];
}