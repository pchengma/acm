// LeetCode: 322. Coin Change (Medium)
class CoinChange {
public:
    int MAX_COINS = 1e9;

    int coinChange(vector<int> &coins, int amount) {
        sort(coins.begin(), coins.end());

        vector<int> minNumCoins(amount + 1, MAX_COINS);
        minNumCoins[0] = 0;

        for (int money = 1; money <= amount; money++) {
            for (int i = 0; i < coins.size() && coins[i] <= money; i++) {
                minNumCoins[money] = min(minNumCoins[money], minNumCoins[money - coins[i]] + 1);
            }
        }

        return minNumCoins[amount] == MAX_COINS ? -1 : minNumCoins[amount];
    }
};