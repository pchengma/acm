// LeetCode: 309. Best Time to Buy and Sell Stock with Cooldown (Medium)
int maxProfit(int *prices, int pricesSize) {
    if (pricesSize == 0) {
        return 0;
    }

    int f[pricesSize][3];
    f[0][0] = -prices[0];
    f[0][1] = f[0][2] = 0;
    for (int i = 1; i < pricesSize; ++i) {
        f[i][0] = fmax(f[i - 1][0], f[i - 1][2] - prices[i]);
        f[i][1] = f[i - 1][0] + prices[i];
        f[i][2] = fmax(f[i - 1][1], f[i - 1][2]);
    }
    return fmax(f[pricesSize - 1][1], f[pricesSize - 1][2]);
}
