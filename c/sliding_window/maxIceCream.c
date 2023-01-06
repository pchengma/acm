// LeetCode: 1833. Maximum Ice Cream Bars (Medium)
int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int maxIceCream(int *costs, int costsSize, int coins) {
    qsort(costs, costsSize, sizeof(int), compare);
    int icecreams = 0;

    for (int i = 0; i < costsSize; i++) {
        if (coins >= costs[i]) {
            coins -= costs[i];
            icecreams++;
        } else {
            break;
        }
    }
    return icecreams;
}