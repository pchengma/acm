// LeetCode: 1260. Shift 2D Grid (Easy)
class Solution {
public:
    vector <vector<int>> shiftGrid(vector <vector<int>> &grid, int k) {
        int dim_row = grid.size();
        int dim_col = grid[0].size();

        vector <vector<int>> ans(dim_row, vector<int>(dim_col, 0));

        for (int i = 0; i < dim_row; ++i) {
            for (int j = 0; j < dim_col; ++j) {
                int row = (i + (j + k) / dim_col) % dim_row;
                int col = (j + k) % dim_col;
                ans[row][col] = grid[i][j];
            }
        }

        return ans;
    }
};