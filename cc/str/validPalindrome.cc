// 680. Valid Palindrome II (Easy)
class Solution {
public:
    bool checkPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                return checkPalindrome(s, i, j - 1) || checkPalindrome(s, i + 1, j);
            }
            ++i;
            --j;
        }

        return true;
    }
};