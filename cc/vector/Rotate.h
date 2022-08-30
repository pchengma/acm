// LeetCode: 48. Rotate Image (Medium)
class Rotate {
public:
    void rotate(vector <vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = n - 1;
            while (left < right) {
                swap(matrix[i][left++], matrix[i][right--]);
            }
        }
    }
};