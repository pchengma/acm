// LeetCode: 14. Longest Common Prefix (Easy)
class LongestCommonPrefix {
public:
    static bool myCompare(string s1, string s2) {
        return s1.length() < s2.length();
    }

    string longestCommonPrefix(vector <string> &strs) {
        sort(strs.begin(), strs.end(), myCompare);

        string ans = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < ans.size(); j++) {
                if (ans[j] != strs[i][j]) {
                    ans.erase(j, ans.length() - j);
                    break;
                }
            }
        }

        return ans;
    }
};