// LeetCode: 804. Unique Morse Code Words (Easy)
class UniqueMorseRepresentations {
public:
    int uniqueMorseRepresentations(vector <string> &words) {
        vector <string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                                 "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                                 "-.--", "--.."};
        unordered_set <string> ans;
        for (auto &word: words) {
            string code = "";
            for (auto &ch: word) {
                code += morse[ch - 'a'];
            }
            ans.insert(code);
        }

        return ans.size();
    }
};