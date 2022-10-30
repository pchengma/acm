// LeetCode: 1293. Shortest Path in a Grid with Obstacles Elimination (Hard)
class ShortestPath {
public:
    int shortestPath(vector <vector<int>> &grid, int k) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1 && m == 1) {
            return 0;
        }

        vector <vector<int>> vis(n, vector<int>(m, -1));
        vector <pair<int, int>> dir = {{1,  0},
                                       {0,  1},
                                       {-1, 0},
                                       {0,  -1}};

        auto check = [&](int x, int y) {
            return x > -1 && x < n && y > -1 && y < m;
        };

        queue <vector<int>> q;
        q.push({0, 0, 0, k});
        vis[0][0] = k;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int row = t[0], col = t[1], towns = t[2], coins = t[3];

            if (row == n - 1 && col == m - 1) {
                return towns;
            }

            if (grid[row][col] == 1) {
                if (!coins) {
                    continue;
                }
                coins--;
            }

            for (auto[dx, dy]: dir) {
                int x = row + dx;
                int y = col + dy;
                if (check(x, y) && (vis[x][y] < coins)) {
                    vis[x][y] = coins;
                    q.push({x, y, towns + 1, coins});
                }
            }
        }

        return -1;
    }
};