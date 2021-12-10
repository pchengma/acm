// LeetCode: 566. Reshape the Matrix (Easy)
class Solution {
public:
    vector <vector<int>> matrixReshape(vector <vector<int>> &mat, int r, int c) {
        int dim_r = mat.size();
        int dim_c = mat[0].size();
        vector <vector<int>> res(r, vector<int>(c));

        if (dim_r * dim_c != (r * c) || (dim_r == r)) {
            return mat;
        }

        for (int i = 0; i < dim_r * dim_c; ++i) {
            res[i / c][i % c] = mat[i / dim_c][i % dim_c];
        }

        return res;
    }
};