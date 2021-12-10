// LeetCode: 118. Pascal's Triangle (Easy)
class Solution {
public:
    vector <vector<int>> generate(int numRows) {
        vector <vector<int>> res(numRows);

        res[0] = {1};

        if (numRows != 1) {
            for (int i = 1; i < numRows; ++i) {
                res[i].push_back(1);
                for (int j = 1; j <= i - 1; ++j) {
                    res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
                res[i].push_back(1);
            }
        }

        return res;
    }
};