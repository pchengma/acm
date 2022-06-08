// LeetCode: 1332. Remove Palindromic Subsequences (Easy)
class RemovePalindromeSub {
public:
    int removePalindromeSub(string s) {
        return 2 - equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }
};
