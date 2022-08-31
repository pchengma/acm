// leetCode: 417. Pacific Atlantic Water Flow (Medium)
class PacificAtlantic {
public:
    vector<int> offset = {0, 1, 0, -1, 0};

    bool checkBounds(int row, int col, int m, int n) {
        return row < 0 || col < 0 || row > m - 1 || col > n - 1;
    }

    void dfs(vector <vector<int>> &matrix, vector <vector<bool>> &visited, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j] = true;
        for (int k = 1; k < offset.size(); k++) {
            int row = i + offset[k], col = j + offset[k - 1];
            if (!checkBounds(row, col, m, n) && !visited[row][col] && matrix[row][col] >= matrix[i][j])
                dfs(matrix, visited, row, col);
        }
    }

    vector <vector<int>> pacificAtlantic(vector <vector<int>> &matrix) {
        vector <vector<int>> r;
        int m = matrix.size();
        int n = matrix[0].size();

        vector <vector<bool>> pacific(m, vector<bool>(n));
        vector <vector<bool>> atlantic(m, vector<bool>(n));

        for (int i = 0; i < m; i++) {
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(matrix, pacific, 0, j);
            dfs(matrix, atlantic, m - 1, j);
        }


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    r.push_back({i, j});
            }
        }

        return r;
    }
};