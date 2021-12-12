// LeetCode: 387. First Unique Character in a String (Easy)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> umap;

        for (auto &i: s) {
            ++umap[i];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (umap[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};