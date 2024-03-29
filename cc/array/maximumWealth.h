// LeetCode: 1672. Richest Customer Wealth (Easy)
class Solution {
public:
    int maximumWealth(vector <vector<int>> &accounts) {
        int max = 0;

        for (int i = 0; i < accounts.size(); ++i) {
            int tmp = 0;
            for (int j = 0; j < accounts[i].size(); ++j) {
                tmp += accounts[i][j];
            }
            if (tmp > max) {
                max = tmp;
            }
        }

        return max;
    }
};