// LeetCode: 878. Nth Magical Number (Hard)
class Solution {
public:
    const int MOD = 1e9 + 7;

    int nthMagicalNumber(int n, int a, int b) {
        long L = lcm(a, b), C = (L / a) + (L / b) - 1, k = (n - 1) / C, ans = 0;
        for (int i = 1, j = 1, magicalNeeded = n - k * C; magicalNeeded; --magicalNeeded) {
            if (a * i < b * j) {
                ans = a * i++;
            } else {
                ans = b * j++;
            }
        }
        return (k * L + ans) % MOD;
    }
};