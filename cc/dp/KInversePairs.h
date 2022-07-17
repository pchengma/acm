// LeetCode: 629. K Inverse Pairs Array (Hard)
const int mod = 1e9 + 7, N = 1010;

class Solution {
public:
    int f[N][N] = {};

    int kInversePairs(int n, int K) {
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            long long s = 0;
            for (int j = 0; j <= K; ++j) {
                s += f[i - 1][j];
                if (j >= i) {
                    s -= f[i - 1][j - i];
                }
                f[i][j] = ((long long) f[i][j] + s) % mod;
            }
        }
        return f[n][K];
    }
};