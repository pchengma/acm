// LeetCode: 1631. Path With Minimum Effort (Medium)
class Solution {
public:
    int minimumEffortPath(vector <vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        const int d[5] = {1, 0, -1, 0, 1};
        int res = 0;
        priority_queue < pair < int, int >, vector < pair < int, int >>, greater < pair <
                                                                         int, int>>> pq; // pair(absolute difference, position)
        vector <vector<bool>> visited(m, vector<bool>(n));

        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto[dif, pos] = pq.top();
            pq.pop();

            int i = pos / n, j = pos % n;
            if (visited[i][j]) continue;

            visited[i][j] = 1;
            res = max(res, dif);
            if (i == m - 1 and j == n - 1) {
                break;
            }

            for (int k = 0; k < 4; k++) {
                int ni = i + d[k], nj = j + d[k + 1];
                if (ni >= 0 and ni < m and nj >= 0 and nj < n and !visited[ni][nj]) {
                    pq.emplace(abs(heights[i][j] - heights[ni][nj]), ni * n + nj);
                }
            }
        }
        return res;
    }
};