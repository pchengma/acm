// LeetCode: 856. Score of Parentheses (Medium)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int bal = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                --bal;
                if (s[i - 1] == '(') {
                    ans += 1 << bal;
                }
            } else {
                ++bal;
            }
        }

        return ans;
    }
};