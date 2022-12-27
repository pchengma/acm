// LeetCode: 2279. Maximum Bags With Full Capacity of Rocks (Medium)
int cmp(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int maximumBags(int *capacity, int capacitySize, int *rocks, int rocksSize, int additionalRocks) {
    int i = 0;

    for (i = 0; i < capacitySize; i++) {
        capacity[i] -= rocks[i];
    }

    qsort(capacity, capacitySize, sizeof(int), cmp);

    for (i = 0; i < capacitySize; i++) {
        additionalRocks -= capacity[i];
        if (additionalRocks < 0) {
            break;
        }
    }

    return i;
}