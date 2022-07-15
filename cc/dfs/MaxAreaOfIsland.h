// LeetCode: 695. Max Area of Island (Medium)
class MaxAreaOfIsland {
public:
    int nr, nc, ans, n, m;

    void f_dfs(int r, int c, int &cnt, vector <vector<int>> &grid) {
        grid[r][c] = 0;

        nr = r + 1;
        nc = c;
        if (nr < n && grid[nr][nc] == 1) {
            f_dfs(nr, nc, ++cnt, grid);
        }
        nr = r - 1;
        nc = c;
        if (nr >= 0 && grid[nr][nc] == 1) {
            f_dfs(nr, nc, ++cnt, grid);
        }
        nr = r;
        nc = c + 1;
        if (nc < m && grid[nr][nc] == 1) {
            f_dfs(nr, nc, ++cnt, grid);
        }
        nr = r;
        nc = c - 1;
        if (nc >= 0 && grid[nr][nc] == 1) {
            f_dfs(nr, nc, ++cnt, grid);
        }
    }

    int maxAreaOfIsland(vector <vector<int>> &grid) {
        ans = 0;
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for (short i = 0; i < n; ++i) {
            for (short j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                cnt = 1;
                f_dfs(i, j, cnt, grid);
                if (cnt > ans) {
                    ans = cnt;
                }
            }
        }
        return ans;
    }
};