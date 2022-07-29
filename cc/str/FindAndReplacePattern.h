// LeetCode: 890. Find and Replace Pattern (Medium)
class FindAndReplacePattern {
public:
    string wordToPattern(string word) {
        map<char, int> m;
        int count = 0, N = word.length();
        string ans = "";

        for (int i = 0; i < N; i++) {
            if (!m.count(word[i])) {
                count++;
                m[word[i]] = count;
            }
            ans += char('0' + m[word[i]]);
        }

        return ans;
    }

    vector <string> findAndReplacePattern(vector <string> &words, string pattern) {
        int N = pattern.length();
        vector <string> ans;

        string comp = wordToPattern(pattern);

        for (string word: words) {
            string temp = wordToPattern(word);
            int i = 0;
            while (i < N) {
                if (comp[i] != temp[i]) {
                    break;
                }
                i++;
            }
            if (i == N) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};