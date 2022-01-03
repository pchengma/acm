// LeetCode: 997. Find the Town Judge (Easy)
class Solution {
public:
    int findJudge(int n, vector <vector<int>> &trust) {
        vector<int> trusted(n, 0);

        for (auto &i: trust) {
            --trusted[i[0] - 1];
            ++trusted[i[1] - 1];
        }

        for (int i = 0; i < n; ++i) {
            if (trusted[i] == n - 1) {
                return i + 1;
            }
        }

        return -1;
    }
};