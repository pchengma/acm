// LeetCode: 1359. Count All Valid Pickup and Delivery Options (Hard)
class Solution {
public:
    int countOrders(int n) {
        long ans = 1;
        int MOD = 1e9 + 7;

        for (int i = 1; i <= 2 * n; ++i) {
            ans = ans * i;

            if (i % 2 == 0) {
                ans = ans / 2;
            }
            ans %= MOD;
        }
        return ans;
    }
};