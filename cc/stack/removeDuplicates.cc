// LeetCode: 1209. Remove All Adjacent Duplicates in String II (Medium)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        vector<int> freq(n, 1);
        stack<int> st;
        string ans;

        st.push(0);

        for (int i = 1; i < n; ++i) {
            if (!st.empty()) {
                if (s[st.top()] == s[i]) {
                    freq[i] = freq[st.top()] + 1;
                }
            }

            st.push(i);

            if (freq[st.top()] == k) {
                for (int i = 0; i < k; ++i) {
                    st.pop();
                }
            }
        }

        while (!st.empty()) {
            ans += s[st.top()];
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};