// LeetCode: 200. Number of Islands (Medium)
class NumIslands {
public:
    void markVis(int x, int y, vector <vector<char>> &grid, vector <vector<int>> &vis) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1' || vis[x][y] != 0) return;

        vis[x][y] = 1;

        int di[] = {1, -1, 0, 0};
        int dj[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            markVis(x + di[i], y + dj[i], grid, vis);
        }
    }

    int numIslands(vector <vector<char>> &grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector <vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    markVis(i, j, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};