// LeetCode: 1329. Sort the Matrix Diagonally (Medium)
class DiagonalSort {
public:
    vector <vector<int>> diagonalSort(vector <vector<int>> &mat) {
        unordered_map < int, priority_queue < int, vector < int >, greater < int>>>mp;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j += 1) {
                mp[i - j].push(mat[i][j]);
            }
        }

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j += 1) {
                mat[i][j] = mp[i - j].top();
                mp[i - j].pop();
            }
        }
        return mat;
    }
};