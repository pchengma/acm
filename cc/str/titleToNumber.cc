// LeetCode: 171. Excel Sheet Column Number (Easy)
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;

        for (auto &i: columnTitle) {
            ans = ans * 26 + (i - 'A' + 1);
        }

        return ans;
    }
};