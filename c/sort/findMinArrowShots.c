// LeetCode: 452. Minimum Number of Arrows to Burst Balloons (Medium)
int cmp(void *_a, void *_b) {
    int *a = *(int **) _a, *b = *(int **) _b;
    return a[1] < b[1] ? -1 : 1;
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize) {
    if (!pointsSize) {
        return 0;
    }
    qsort(points, pointsSize, sizeof(int *), cmp);
    int pos = points[0][1];
    int ans = 1;
    for (int i = 0; i < pointsSize; ++i) {
        if (points[i][0] > pos) {
            pos = points[i][1];
            ++ans;
        }
    }
    return ans;
}
