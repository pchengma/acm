// LeetCode: 338. Counting Bits (Easy)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        res.push_back(0);

        for (int i = 1; i <= n; ++i) {
            res.push_back(res[i & (i - 1)] + 1);
        }

        return res;
    }
};