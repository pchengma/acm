// LeetCode: 316. Remove Duplicate Letters (Medium)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0), vis(26, 0);

        string res = "";

        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i] - 'a'];
        }

        for (int i = 0; i < s.size(); ++i) {
            --cnt[s[i] - 'a'];

            if (!vis[s[i] - 'a']) {
                while (res.size() > 0 && res.back() > s[i] && cnt[res.back() - 'a'] > 0) {
                    vis[res.back() - 'a'] = 0;
                    res.pop_back();
                }

                res += s[i];
                vis[s[i] - 'a'] = 1;
            }
        }

        return res;
    }
};