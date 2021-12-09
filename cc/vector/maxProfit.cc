// LeetCode: 121. Best Time to Buy and Sell Stock (Easy)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min_price = 10000;
        int max_profit = 0;

        for (auto i: prices) {
            if (i < min_price) {
                min_price = i;
            } else if (i - min_price > max_profit) {
                max_profit = i - min_price;
            }
        }

        return max_profit;
    }
};