// LeetCode: 1446. Consecutive Characters (Easy)
class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int j = i + 1;
            while (j < s.size() && s[j] == s[j - 1]) {
                ++j;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};