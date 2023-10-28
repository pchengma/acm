// LeetCode: 2558. Take Gifts From the Richest Pile (Easy)
int GetMaxPos(int *gifts, int giftsSize) {
    int pos = 0;
    int max = gifts[0];
    for (int i = 0; i < giftsSize; i++) {
        if (max < gifts[i]) {
            max = gifts[i];
            pos = i;
        }
    }
    return pos;
}

long long pickGifts(int *gifts, int giftsSize, int k) {
    for (int i = 0; i < k; i++) {
        int pos = GetMaxPos(gifts, giftsSize);
        gifts[pos] = (int) sqrt(gifts[pos]);
    }
    long long sum = 0;
    for (int i = 0; i < giftsSize; i++) {
        sum += gifts[i];
    }
    return sum;
}