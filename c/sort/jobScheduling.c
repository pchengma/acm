// LeetCode: 1235. Maximum Profit in Job Scheduling (Hard)
typedef struct Node {
    int start;
    int end;
    int profit;
} node;

int cmp(const void *a, const void *b) {
    return (*(node *) a).end - (*(node *) b).end;
}

int jobScheduling(int *startTime, int startTimeSize, int *endTime, int endTimeSize, int *profit, int profitSize) {
    node *block = (node *) malloc(startTimeSize * sizeof(node));
    int *temp = (int *) malloc(startTimeSize * sizeof(int));
    for (int i = 0; i < startTimeSize; i++) {
        block[i].start = startTime[i];
        block[i].end = endTime[i];
        block[i].profit = profit[i];
        temp[i] = 0;
    }
    qsort(block, startTimeSize, sizeof(node), cmp);
    temp[0] = block[0].profit;
    for (int i = 1; i < startTimeSize; i++) {
        int t = 0;
        for (int j = i - 1; j >= 0; j--)
            if (block[j].end <= block[i].start) {
                t = temp[j];
                break;
            }
        temp[i] = t + block[i].profit < temp[i - 1] ? temp[i - 1] : t + block[i].profit;
    }
    return temp[startTimeSize - 1];
}