// LeetCode: 1962. Remove Stones to Minimize the Total (Medium)
int minStoneSum(int *piles, int pilesSize, int k) {
    int i = 0;
    int table[10001] = {0};
    int maxIndex = 10000;
    int res = 0;

    for (i = 0; i < pilesSize; i++) {
        table[piles[i]]++;
        res += piles[i];
    }
    for (i = 0; i < k; i++) {
        while (maxIndex > 0 && table[maxIndex] == 0) {
            maxIndex--;
        }
        if (table[maxIndex]) {
            int num = (maxIndex + 1) / 2;
            res -= maxIndex - num;
            table[num]++;
            table[maxIndex]--;
        }
    }
    return res;
}