class Solution {
public:
    bool searchMatrix(vector <vector<int>> &matrix, int target) {
        int row = 0, c = matrix[0].size() - 1, l = 0;
        while ((row < matrix.size()) && (target > matrix[row][c])) {
            ++row;
        }

        if (row == matrix.size()) {
            return false;
        }

        while (l <= c) {
            int mid = l + (c - l) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                --c;
            } else {
                l++;
            }
        }
        return false;
    }
};