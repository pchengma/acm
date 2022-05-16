// LeetCode: 1091. Shortest Path in Binary Matrix (Medium)
class Solution {
public:
    int bfs(vector <vector<int>> &A) {
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        queue <vector<int>> q;

        int m = A.size();
        int n = A[0].size();

        vector <vector<int>> visited(m, vector<int>(n, 0));
        q.push({0, 0, 1});
        A[0][0] = 1;

        while (!q.empty()) {
            vector<int> node = q.front();
            q.pop();
            if (node[0] == m - 1 && node[1] == n - 1) {
                return node[2];
            }

            for (int i = 0; i < 8; ++i) {
                int x = node[0] + dx[i];
                int y = node[1] + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == 0 && A[x][y] == 0) {
                    q.push({x, y, node[2] + 1});
                    visited[x][y] = 1;
                }
            }
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector <vector<int>> &A) {
        if (A[0][0]) {
            return -1;
        }

        return bfs(A);
    }
};