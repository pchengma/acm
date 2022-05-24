// LeetCode: 32. Longest Valid Parentheses (Medium)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == ')' && st.top() != -1 && s[st.top()] == '(') {
                st.pop();
                ans = max(ans, i - st.top());
            } else {
                st.push(i);
            }
        }

        return ans;
    }
};