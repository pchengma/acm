// LeetCode: 121. Best Time to Buy and Sell Stock (Easy)
int maxProfit(int *prices, int pricesSize) {
    int max = 0, cur_cost, dp_prev, dp_cur;
    dp_prev = 0;

    for (int i = 1; i < pricesSize; ++i, dp_prev = dp_cur) {
        cur_cost = (prices[i] - prices[i - 1]) + dp_prev;
        dp_cur = cur_cost < 0 ? 0 : cur_cost;
        max = dp_cur > max ? dp_cur : max;
    }
    return max;
}
