// LeetCode: 389. Find the Difference (Easy)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int result = 0;

        for (int i = 0; i < s.size(); ++i) {
            result -= s[i];
            result += t[i];
        }

        result += t[s.size()];

        return result;
    }
};