// LeetCode: 242. Valid Anagram (Easy)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        } else {
            unordered_map<char, int> umap;

            for (auto &i: t) {
                ++umap[i];
            }

            for (auto &i: s) {
                if (umap[i] == 0) {
                    return false;
                } else {
                    --umap[i];
                }
            }

            return true;
        }
    }
};