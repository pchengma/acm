// LeetCode: 345. Reverse Vowels of a String (Easy)
class ReverseVowels {
public:
    string reverseVowels(string s) {
        set<char> vwls = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0, r = s.size() - 1;
        while (l < r) {
            l += !vwls.count(s[l]);
            r -= !vwls.count(s[r]);
            if (vwls.count(s[l]) && vwls.count(s[r]))
                swap(s[l++], s[r--]);
        }
        return s;
    }
};