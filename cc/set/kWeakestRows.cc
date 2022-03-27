// LeetCode: 1337. The K Weakest Rows in a Matrix (Easy)
class Solution {
public:
    vector<int> kWeakestRows(vector <vector<int>> &mat, int k) {
        vector<int> ans;

        if (k == 0) {
            return ans;
        }

        set <pair<int, int>> s;
        for (int i = 0; i < mat.size(); ++i) {
            int cnt = count(mat[i].begin(), mat[i].end(), 1);
            s.insert({cnt, i});
        }

        for (auto &i: s) {
            ans.push_back(i.second);
            --k;
            if (k == 0) {
                break;
            }
        }

        return ans;
    }
};