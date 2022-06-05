// LeetCode: 52. N-Queens II (Hard)
class TotalNQueens {
public:
    int dfs(int i, int n, int l, int c, int r) {
        if (i == n) {
            return 1;
        }

        l <<= 1, r >>= 1;
        int mask = l | c | r;
        int res = 0;
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == 0) {
                res += dfs(i + 1, n, l | (1 << j), c | (1 << j), r | (1 << j));
            }
        }
        return res;
    }

    int totalNQueens(int n) {
        return dfs(0, n, 0, 0, 0);
    }
};